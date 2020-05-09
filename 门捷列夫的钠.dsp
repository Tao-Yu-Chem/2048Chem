# Microsoft Developer Studio Project File - Name="门捷列夫的钠" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=门捷列夫的钠 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "门捷列夫的钠.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "门捷列夫的钠.mak" CFG="门捷列夫的钠 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "门捷列夫的钠 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "门捷列夫的钠 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "门捷列夫的钠 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "门捷列夫的钠 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "门捷列夫的钠 - Win32 Release"
# Name "门捷列夫的钠 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\yxsmdlg.cpp
# End Source File
# Begin Source File

SOURCE=".\门捷列夫的钠.cpp"
# End Source File
# Begin Source File

SOURCE=".\门捷列夫的钠.rc"
# End Source File
# Begin Source File

SOURCE=".\门捷列夫的钠Dlg.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\yxsmdlg.h
# End Source File
# Begin Source File

SOURCE=".\门捷列夫的钠.h"
# End Source File
# Begin Source File

SOURCE=".\门捷列夫的钠Dlg.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\017氨.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\052氰.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\10氖.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\11钠.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\12镁.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\13铝.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\14硅.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\15磷.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\16硫.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\17氯.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\1氢.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\2氦.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\3锂.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\4铍.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\5硼.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\6碳.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\7氮.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\8氧.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\9氟.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\bitmap0.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_bg.bmp
# End Source File
# Begin Source File

SOURCE=".\res\门捷列夫的钠.ico"
# End Source File
# Begin Source File

SOURCE=".\res\门捷列夫的钠.rc2"
# End Source File
# Begin Source File

SOURCE=".\res\陶豫.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
