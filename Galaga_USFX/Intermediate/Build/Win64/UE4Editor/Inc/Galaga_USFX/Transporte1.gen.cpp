// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/Transporte1.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTransporte1() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_ATransporte1_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ATransporte1();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveTransporte();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
// End Cross Module References
	void ATransporte1::StaticRegisterNativesATransporte1()
	{
	}
	UClass* Z_Construct_UClass_ATransporte1_NoRegister()
	{
		return ATransporte1::StaticClass();
	}
	struct Z_Construct_UClass_ATransporte1_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATransporte1_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveTransporte,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATransporte1_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Transporte1.h" },
		{ "ModuleRelativePath", "Transporte1.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATransporte1_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATransporte1>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATransporte1_Statics::ClassParams = {
		&ATransporte1::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ATransporte1_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATransporte1_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATransporte1()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATransporte1_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATransporte1, 467588805);
	template<> GALAGA_USFX_API UClass* StaticClass<ATransporte1>()
	{
		return ATransporte1::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATransporte1(Z_Construct_UClass_ATransporte1, &ATransporte1::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("ATransporte1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATransporte1);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
