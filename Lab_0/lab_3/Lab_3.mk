##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab_3
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/sh3ai/Desktop/C++/C++
ProjectPath            :=C:/Users/sh3ai/Desktop/ECEGR2020/Lab_0/Lab_3/Lab_3
IntermediateDirectory  :=../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3
OutDir                 :=../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=sh3ai
Date                   :=15/02/2022
CodeLitePath           :=C:/Tools/CodeLite
LinkerName             :=C:/Tools/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/Tools/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\..\..\..\C++\C++\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/Tools/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/Tools/mingw64/bin/ar.exe rcu
CXX      := C:/Tools/mingw64/bin/g++.exe
CC       := C:/Tools/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/Tools/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Python\CodeLite
Objects0=../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/.d $(Objects) 
	@if not exist "..\..\..\..\C++\C++\build-$(ConfigurationName)\__\__\ECEGR2020\Lab_0\lab_3\lab_3" mkdir "..\..\..\..\C++\C++\build-$(ConfigurationName)\__\__\ECEGR2020\Lab_0\lab_3\lab_3"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\..\..\..\C++\C++\build-$(ConfigurationName)\__\__\ECEGR2020\Lab_0\lab_3\lab_3" mkdir "..\..\..\..\C++\C++\build-$(ConfigurationName)\__\__\ECEGR2020\Lab_0\lab_3\lab_3"
	@if not exist ""..\..\..\..\C++\C++\build-$(ConfigurationName)\bin"" mkdir ""..\..\..\..\C++\C++\build-$(ConfigurationName)\bin""

../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/.d:
	@if not exist "..\..\..\..\C++\C++\build-$(ConfigurationName)\__\__\ECEGR2020\Lab_0\lab_3\lab_3" mkdir "..\..\..\..\C++\C++\build-$(ConfigurationName)\__\__\ECEGR2020\Lab_0\lab_3\lab_3"

PreBuild:


##
## Objects
##
../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(ObjectSuffix): lab_3.c ../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/sh3ai/Desktop/ECEGR2020/Lab_0/Lab_3/Lab_3/lab_3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lab_3.c$(ObjectSuffix) $(IncludePath)
../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(DependSuffix): lab_3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(ObjectSuffix) -MF../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(DependSuffix) -MM lab_3.c

../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(PreprocessSuffix): lab_3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3/lab_3.c$(PreprocessSuffix) lab_3.c


-include ../../../../C++/C++/build-$(ConfigurationName)/__/__/ECEGR2020/Lab_0/lab_3/lab_3//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


