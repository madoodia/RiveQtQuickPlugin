@REM SPDX-FileCopyrightText: 2023 Jeremias Bosch <jeremias.bosch@basyskom.com>
@REM SPDX-FileCopyrightText: 2023 Jonas Kalinka <jonas.kalinka@basyskom.com>
@REM SPDX-FileCopyrightText: 2023 basysKom GmbH
@REM SPDX-FileCopyrightText: 2023 Reza Aarabi <madoodia@gmail.com>

@REM SPDX-License-Identifier: LGPL-3.0-or-later
@REM --------------------------------------------------------------------------

set ROOT=%~dp0

set PATH=%PATH%;%SDKS_LOCATION%/Qt5/bin
@REM set PATH=%PATH%;%SDKS_LOCATION%/Qt6/bin

set QML2_IMPORT_PATH=%ROOT%\build\binary

@REM CALL %ROOT%\build_2019_Qt5_Release\binary\examples\RiveQtQuickPlugin\RiveQtQuickSimpleViewer.exe
@REM CALL %ROOT%\build_2019_Qt6_Release\binary\examples\RiveQtQuickPlugin\RiveQtQuickSimpleViewer.exe
@REM CALL %ROOT%\build_2022_Qt5_Release\binary\examples\RiveQtQuickPlugin\RiveQtQuickSimpleViewer.exe
CALL %ROOT%\build\binary\examples\RiveQtQuickPlugin\RiveQtQuickSimpleViewer.exe
