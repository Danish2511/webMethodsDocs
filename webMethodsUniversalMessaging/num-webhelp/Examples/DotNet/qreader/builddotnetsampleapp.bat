set args=%1.cs
if NOT "%2"=="" set args=%args% %2.cs
if NOT "%3"=="" set args=%args% %3.cs
if NOT "%4"=="" set args=%args% %4.cs
if NOT "%5"=="" set args=%args% %5.cs
if NOT "%6"=="" set args=%args% %6.cs
if NOT "%7"=="" set args=%args% %7.cs
if NOT "%8"=="" set args=%args% %8.cs
if NOT "%9"=="" set args=%args% %9.cs
C:\WINDOWS\Microsoft.NET\Framework\v3.5\Csc.exe ^
/noconfig ^
/nowarn:1701,1702,1591,1592,1573,1571,1570,1572,1574,672,108,114 ^
/errorreport:prompt ^
/warn:4 ^
/define:TRACE ^
/debug:pdbonly ^
/filealign:512 ^
/optimize+ ^
/reference:"..\..\bin\Nirvana DotNet.dll" ^
/reference:"..\..\bin\nSampleApp.dll" ^
/reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.5\System.Core.dll" ^
/reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.5\System.Data.DataSetExtensions.dll" ^
/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Data.dll ^
/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Deployment.dll ^
/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.dll ^
/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Drawing.dll ^
/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Windows.Forms.dll ^
/reference:C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.Xml.dll ^
/reference:"C:\Program Files\Reference Assemblies\Microsoft\Framework\v3.5\System.Xml.Linq.dll" ^
/out:..\..\bin\%1.exe /target:exe %args% Properties\AssemblyInfo.cs
