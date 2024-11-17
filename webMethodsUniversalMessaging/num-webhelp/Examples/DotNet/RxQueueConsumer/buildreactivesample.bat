set args=%1.cs
if NOT "%2"=="" set args=%args% %2.cs
if NOT "%3"=="" set args=%args% %3.cs
if NOT "%4"=="" set args=%args% %4.cs
if NOT "%5"=="" set args=%args% %5.cs
if NOT "%6"=="" set args=%args% %6.cs
if NOT "%7"=="" set args=%args% %7.cs
if NOT "%8"=="" set args=%args% %8.cs
if NOT "%9"=="" set args=%args% %9.cs
C:\WINDOWS\Microsoft.NET\Framework\v4.0\Csc.exe ^
/noconfig ^
/nostdlib ^
/nowarn:1701,1702,1591,1592,1573,1571,1570,1572,1574,672,108,114 ^
/errorreport:prompt ^
/warn:1 ^
/define:TRACE ^
/debug:pdbonly ^
/filealign:512 ^
/optimize+ ^
/reference:"..\..\bin\Nirvana.Reactive.dll" ^
/reference:"..\..\bin\Nirvana DotNet.dll" ^
/reference:"..\..\bin\nSampleApp.dll" ^
/reference:../Nirvana.Reactive/lib/System.Reactive.Core.dll ^
/reference:../Nirvana.Reactive/lib/System.Reactive.Interfaces.dll ^
/reference:../Nirvana.Reactive/lib/System.Reactive.Linq.dll ^
/reference:../Nirvana.Reactive/lib/System.Reactive.PlatformServices.dll ^
/reference:../Nirvana.Reactive/lib/System.Reactive.Windows.Threading.dll ^
/reference:"C:\WINDOWS\Microsoft.NET\Framework\v4.0\System.Core.dll" ^
/reference:"C:\WINDOWS\Microsoft.NET\Framework\v4.0\mscorlib.dll" ^
/out:..\..\bin\%1.exe /target:exe %args% Properties\AssemblyInfo.cs
