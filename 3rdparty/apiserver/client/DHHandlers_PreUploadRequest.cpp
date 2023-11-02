/**
 * Deepin官网
 * deepin的官方网站后台接口
 *
 * The version of the OpenAPI document: 1.0
 * Contact: wurongjie@deepin.org
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "DHHandlers_PreUploadRequest.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "DHHelpers.h"

namespace DeepinHomeAPI {

DHHandlers_PreUploadRequest::DHHandlers_PreUploadRequest(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

DHHandlers_PreUploadRequest::DHHandlers_PreUploadRequest() {
    this->initializeModel();
}

DHHandlers_PreUploadRequest::~DHHandlers_PreUploadRequest() {}

void DHHandlers_PreUploadRequest::initializeModel() {

    m_name_isSet = false;
    m_name_isValid = false;

    m_size_isSet = false;
    m_size_isValid = false;
}

void DHHandlers_PreUploadRequest::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void DHHandlers_PreUploadRequest::fromJsonObject(QJsonObject json) {

    m_name_isValid = ::DeepinHomeAPI::fromJsonValue(name, json[QString("name")]);
    m_name_isSet = !json[QString("name")].isNull() && m_name_isValid;

    m_size_isValid = ::DeepinHomeAPI::fromJsonValue(size, json[QString("size")]);
    m_size_isSet = !json[QString("size")].isNull() && m_size_isValid;
}

QString DHHandlers_PreUploadRequest::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject DHHandlers_PreUploadRequest::asJsonObject() const {
    QJsonObject obj;
    if (m_name_isSet) {
        obj.insert(QString("name"), ::DeepinHomeAPI::toJsonValue(name));
    }
    if (m_size_isSet) {
        obj.insert(QString("size"), ::DeepinHomeAPI::toJsonValue(size));
    }
    return obj;
}

QString DHHandlers_PreUploadRequest::getName() const {
    return name;
}
void DHHandlers_PreUploadRequest::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}

bool DHHandlers_PreUploadRequest::is_name_Set() const{
    return m_name_isSet;
}

bool DHHandlers_PreUploadRequest::is_name_Valid() const{
    return m_name_isValid;
}

qint32 DHHandlers_PreUploadRequest::getSize() const {
    return size;
}
void DHHandlers_PreUploadRequest::setSize(const qint32 &size) {
    this->size = size;
    this->m_size_isSet = true;
}

bool DHHandlers_PreUploadRequest::is_size_Set() const{
    return m_size_isSet;
}

bool DHHandlers_PreUploadRequest::is_size_Valid() const{
    return m_size_isValid;
}

bool DHHandlers_PreUploadRequest::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_name_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_size_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool DHHandlers_PreUploadRequest::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_name_isValid && m_size_isValid && true;
}

} // namespace DeepinHomeAPI