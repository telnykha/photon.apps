; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=blood41
AppVerName=blood41 1.0.0
AppPublisher=NN-VideoLab
DefaultDirName={pf}\NN-VideoLab
DefaultGroupName=blood41
LicenseFile=C:\_alt\blood\license_blood.txt
OutputDir=C:\_alt\blood\Win32
OutputBaseFilename=blood41_setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\_alt\blood\Win32\Release\Blood41.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Program Files (x86)\Embarcadero\Studio\19.0\bin\borlndmm.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Program Files (x86)\Embarcadero\Studio\19.0\bin\cc32250mt.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\blood41"; Filename: "{app}\Blood41.exe"
Name: "{userdesktop}\blood41"; Filename: "{app}\Blood41.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\blood41"; Filename: "{app}\Blood41.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\Blood41.exe"; Description: "{cm:LaunchProgram,blood41}"; Flags: nowait postinstall skipifsilent

