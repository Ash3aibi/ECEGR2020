##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab_0
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/sh3ai/Desktop/C++/C++
ProjectPath            :=C:/Users/sh3ai/Desktop/C++/ECEGR2020/Lab_0
IntermediateDirectory  :=../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0
OutDir                 :=../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=sh3ai
Date                   :=09/01/2022
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
OutputFile             :=..\..\C++\build-$(ConfigurationName)\bin\$(ProjectName)
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
Objects0=../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/.d $(Objects) 
	@if not exist "..\..\C++\build-$(ConfigurationName)\__\ECEGR2020\Lab_0" mkdir "..\..\C++\build-$(ConfigurationName)\__\ECEGR2020\Lab_0"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\..\C++\build-$(ConfigurationName)\__\ECEGR2020\Lab_0" mkdir "..\..\C++\build-$(ConfigurationName)\__\ECEGR2020\Lab_0"
	@if not exist ""..\..\C++\build-$(ConfigurationName)\bin"" mkdir ""..\..\C++\build-$(ConfigurationName)\bin""

../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/.d:
	@if not exist "..\..\C++\build-$(ConfigurationName)\__\ECEGR2020\Lab_0" mkdir "..\..\C++\build-$(ConfigurationName)\__\ECEGR2020\Lab_0"

PreBuild:


##
## Objects
##
../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(ObjectSuffix): main.c ../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/sh3ai/Desktop/C++/ECEGR2020/Lab_0/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(ObjectSuffix) -MF../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(DependSuffix) -MM main.c

../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0/main.c$(PreprocessSuffix) main.c


-include ../../C++/build-$(ConfigurationName)/__/ECEGR2020/Lab_0//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


