@REM SPDX-FileCopyrightText: 2023 Jeremias Bosch <jeremias.bosch@basyskom.com>
@REM SPDX-FileCopyrightText: 2023 Jonas Kalinka <jonas.kalinka@basyskom.com>
@REM SPDX-FileCopyrightText: 2023 basysKom GmbH
@REM SPDX-FileCopyrightText: 2023 Reza Aarabi <madoodia@gmail.com>

@REM SPDX-License-Identifier: LGPL-3.0-or-later
@REM --------------------------------------------------------------------------

@REM Getting the Root Directory When this file will be run
set ROOT=%~dp0

cd %ROOT%
if not exist "deploy" (
    mkdir "deploy"
)


copy %ROOT%\build\binary\examples\RiveQtQuickPlugin\RiveQtQuickSimpleViewer.exe "%ROOT%\deploy"


CALL %SDKS_LOCATION%\Qt5\bin\windeployqt.exe %ROOT%\deploy\RiveQtQuickSimpleViewer.exe --no-translations

