import os
from os import listdir
from os.path import isfile, join

def getListOfFiles(dirName):
    # create a list of file and sub directories 
    # names in the given directory 
    listOfFile = os.listdir(dirName)
    allFiles = list()
    # Iterate over all the entries
    for entry in listOfFile:
        # Create full path
        fullPath = os.path.join(dirName, entry)
        # If entry is a directory then get the list of files in this directory 
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(fullPath)
                
    return allFiles

def fast_scandir(dirname):
    subfolders= [f.path for f in os.scandir(dirname) if f.is_dir()]
    for dirname in list(subfolders):
        subfolders.extend(fast_scandir(dirname))
    return subfolders

sourceFolder = "source"
cwd = os.getcwd() + os.sep + ".." + os.sep + sourceFolder
linesСonnector = " ^" 

print(cwd)

buildScript = open("build.bat");
newBuildScript = ""
isNeedToSkipSources = False
isNeedToSkipHeaders = False

for line in buildScript.readlines():
    if isNeedToSkipSources:
        isNeedToSkipSources = line[0] != '-'

    if isNeedToSkipHeaders:
        isNeedToSkipHeaders = "-I " in line

    if (not isNeedToSkipSources) and (not isNeedToSkipHeaders):
        newBuildScript += line
    
    if line == "g++ ^\n":
        isNeedToSkipSources = True
        for file in getListOfFiles(cwd):
            sourceFile = file.replace(cwd, sourceFolder)
            if sourceFile.split(".")[-1] == "cpp" :
                print(sourceFile) 
                newBuildScript += "    " + sourceFile + linesСonnector + "\n"
        print("_______")


    if "-I " in line and not isNeedToSkipHeaders:
        isNeedToSkipHeaders = True
        for dir in fast_scandir(cwd):
            headersDir = dir.replace(cwd, sourceFolder)
            print(headersDir)
            newBuildScript += "-I " + headersDir + linesСonnector + "\n"
        newBuildScript += "-I " + sourceFolder + linesСonnector + "\n"

print("_______")
# print(newBuildScript)

buildScript.close()
buildScript = open("build.bat", "w");
buildScript.write(newBuildScript)
buildScript.close()