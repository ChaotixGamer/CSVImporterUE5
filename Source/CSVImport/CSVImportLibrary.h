// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSVImportLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CSVIMPORT_API UCSVImportLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "CSVImportLibrary")
	static TArray<FString> ReadCSVFile(const FString& FileName);

	UFUNCTION(BlueprintCallable, Category = "CSVImportLibrary")
	static TArray<FString> SplitLineCSV(const TArray<FString>& CSVArray, int LineIndex, const bool bIgnoreFirstLine = true);
};
