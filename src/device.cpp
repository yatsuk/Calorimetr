#include "device.h"
#include "tercon.h"
#include "mit_8_20.h"
#include "lt300.h"
#include <QTime>
#include <QDebug>

DeviceManager::DeviceManager(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType <TerconData>();
}

DeviceManager::~DeviceManager()
{

}

Device * DeviceManager::createDeviceFromJSON(const json &parameters)
{
    Device * device = nullptr;

    if (!parameters.empty()){
        if (QString::compare(parameters["type"].get<std::string>().c_str(), "Tercon") == 0){
            device = new Tercon;

            if(!device->initialization()){
                qDebug() << "initialization fail";
            }
            device->setObjectName(parameters["id"].get<std::string>().c_str());
            if(!device->setSetting(parameters)){
                qDebug() << "set settings fail";
            }
        } else if(QString::compare(parameters["type"].get<std::string>().c_str(), "Mit_8_20") == 0){
            device = new Mit_8_20;

            if(!device->initialization()){
                qDebug() << "initialization fail";
            }
            device->setObjectName(parameters["id"].get<std::string>().c_str());
            if(!device->setSetting(parameters)){
                qDebug() << "set settings fail";
            }
        } else if(QString::compare(parameters["type"].get<std::string>().c_str(), "Lt300") == 0){
            device = new LT300;

            if(!device->initialization()){
                qDebug() << "initialization fail";
            }
            device->setObjectName(parameters["id"].get<std::string>().c_str());
            if(!device->setSetting(parameters)){
                qDebug() << "set settings fail";
            }
        }
    }
    devices.push_back(device);
    return device;
}

bool DeviceManager::destroyDevices()
{    
    while (!devices.isEmpty()) {
        Device * device = devices.back();
        device->stop();
        device->disconnectDevice();
        delete device;
        devices.pop_back();
    }

    return true;
}






Device::Device(QObject *parent) :
    QObject(parent)
{
    deviceTimer_ = new QTimer(this);
    deviceTimer_->setSingleShot(true);
    connect(deviceTimer_, &QTimer::timeout, this, &Device::deviceTimerTimeout);
}

Device::~Device()
{

}

bool Device::setSetting(const json &parameters)
{
    parameters_ = parameters;
    deviceTimerTimeout_ = parameters_["deviceTimeout"].get<int>();
    return true;
}

void Device::deviceTimerTimeout()
{
    emit message(tr("Предупрежение! Устройство \"%1\": В течение %2 мс устройство не передаёт данные.").arg(parameters_["name"].get<std::string>().c_str()).arg(deviceTimerTimeout_),Shared::warning);
    deviceNotWorking_ = true;
}

void Device::deviceDataSended()
{
    if(deviceNotWorking_){
        emit message(tr("Предупрежение! Устройство \"%1\": Устройство возобновило передачу данных.").arg(parameters_["name"].get<std::string>().c_str()),Shared::warning);
    }
    deviceNotWorking_ = false;
    resetTimeoutTimer();
}

void Device::resetTimeoutTimer()
{
    deviceTimer_->start(deviceTimerTimeout_);
}

void Device::stopTimeoutTimer()
{
    deviceTimer_->stop();
}


