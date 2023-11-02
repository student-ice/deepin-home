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

/**
 * Representing a Server configuration.
 */
#ifndef DH_SERVERVCONFIGURATION_H
#define DH_SERVERVCONFIGURATION_H

#include <QString>
#include <QMap>
#include <QRegularExpression>
#include <QUrl>
#include <stdexcept>
#include "DHServerVariable.h"

namespace DeepinHomeAPI {

class DHServerConfiguration {
public:
    /**
     * @param url A URL to the target host.
     * @param description A description of the host designated by the URL.
     * @param variables A map between a variable name and its value. The value is used for substitution in the server's URL template.
     */
    DHServerConfiguration(const QUrl &url, const QString &description, const QMap<QString, DHServerVariable> &variables)
    : _description(description),
      _variables(variables),
      _url(url){}
    DHServerConfiguration(){}
    ~DHServerConfiguration(){}

    /**
     * Format URL template using given variables.
     *
     * @param variables A map between a variable name and its value.
     * @return Formatted URL.
     */
    QString URL() {
        QString url = _url.toString();
        if(!_variables.empty()){
            // go through variables and replace placeholders
            for (auto const& v : _variables.keys()) {
                QString name = v;
                DHServerVariable serverVariable = _variables.value(v);
                QString value = serverVariable._defaultValue;

                if (!serverVariable._enumValues.empty() && !serverVariable._enumValues.contains(value)) {
                    throw std::runtime_error(QString("The variable " + name + " in the server URL has invalid value " + value + ".").toUtf8().toStdString());
                }
                QRegularExpression regex(QString("\\{" + name + "\\}"));
                url = url.replace(regex, value);

            }
            return url;
        }
        return url;
    }

    int setDefaultValue(const QString &variable,const QString &value){
      if(_variables.contains(variable))
        return _variables[variable].setDefaultValue(value);
      return -1;
    }

    QString _description;
    QMap<QString, DHServerVariable> _variables;
    QUrl _url;

};

} // namespace DeepinHomeAPI

#endif // DH_SERVERVCONFIGURATION_H