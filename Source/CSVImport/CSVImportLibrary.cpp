// Fill out your copyright notice in the Description page of Project Settings.


#include "CSVImportLibrary.h"
#include "Misc/FileHelper.h"


TArray<FString> UCSVImportLibrary::ReadCSVFile(const FString& FileName) {

    FString Contents;
    TArray<FString> SplitContents;
    
    TArray<FString> CSVFileList;
    
    const FString ContentDirectory = FPaths::ProjectContentDir();
    FPlatformFileManager::Get().GetPlatformFile().FindFiles(CSVFileList, *ContentDirectory, TEXT("csv"));

    for (const auto& FilePath : CSVFileList)
    {
        if (FilePath.Contains(FileName))
        {
            FFileHelper::LoadFileToString(Contents, *FilePath);
        }
    }

    Contents.ParseIntoArrayLines(SplitContents);
    return SplitContents;
}

TArray<FString> UCSVImportLibrary::SplitLineCSV(const TArray<FString>& CSVArray, int LineIndex,
    const bool bIgnoreFirstLine)
{
    TArray<FString> LineContents;

    if(bIgnoreFirstLine)
        LineIndex++;

    if(CSVArray.Num() > LineIndex)
    {
        CSVArray[LineIndex].ParseIntoArray(LineContents, TEXT(","));   
    }
    
    return LineContents;
}
