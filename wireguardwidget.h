/*

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WIREGUARDWIDGET_H
#define WIREGUARDWIDGET_H

#include "settingwidget.h"

#include <QProcess>

#include "ui_wireguard.h"

#include <NetworkManagerQt/VpnSetting>

class QUrl;
class QLineEdit;

class WireGuardSettingWidget : public SettingWidget
{
    Q_OBJECT
public:
    explicit WireGuardSettingWidget(const NetworkManager::VpnSetting::Ptr &setting, QWidget *parent = 0);
    ~WireGuardSettingWidget();

    void loadConfig(const NetworkManager::Setting::Ptr &setting) Q_DECL_OVERRIDE;
    void loadSecrets(const NetworkManager::Setting::Ptr &setting) Q_DECL_OVERRIDE;

    QVariantMap setting() const;

    virtual bool isValid() const;

private Q_SLOTS:
    void showAdvanced();

private:
    class Private;
    Private *d;
    bool isAddressValid() const;
    bool isPrivateKeyValid() const;
    bool isDNSValid() const;
    bool isPublicKeyValid() const;
    bool isAllowedIPsValid() const;
    bool isEndpointValid() const;
    void setOrClear(NMStringMap &data, QLatin1String key, QString value) const;

};

#endif // WIREGUARDWIDGET_H
