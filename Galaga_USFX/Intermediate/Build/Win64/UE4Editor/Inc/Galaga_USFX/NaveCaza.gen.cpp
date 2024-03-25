// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/NaveCaza.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveCaza() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveCaza_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveCaza();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANave_Enemiga();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
// End Cross Module References
	void ANaveCaza::StaticRegisterNativesANaveCaza()
	{
	}
	UClass* Z_Construct_UClass_ANaveCaza_NoRegister()
	{
		return ANaveCaza::StaticClass();
	}
	struct Z_Construct_UClass_ANaveCaza_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveCaza_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANave_Enemiga,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveCaza_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "NaveCaza.h" },
		{ "ModuleRelativePath", "NaveCaza.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveCaza_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveCaza>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveCaza_Statics::ClassParams = {
		&ANaveCaza::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANaveCaza_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveCaza_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveCaza()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveCaza_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveCaza, 3220472845);
	template<> GALAGA_USFX_API UClass* StaticClass<ANaveCaza>()
	{
		return ANaveCaza::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveCaza(Z_Construct_UClass_ANaveCaza, &ANaveCaza::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("ANaveCaza"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveCaza);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
