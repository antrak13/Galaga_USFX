// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/Caza2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCaza2() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_ACaza2_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ACaza2();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveCaza();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
// End Cross Module References
	void ACaza2::StaticRegisterNativesACaza2()
	{
	}
	UClass* Z_Construct_UClass_ACaza2_NoRegister()
	{
		return ACaza2::StaticClass();
	}
	struct Z_Construct_UClass_ACaza2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACaza2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveCaza,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACaza2_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Caza2.h" },
		{ "ModuleRelativePath", "Caza2.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACaza2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACaza2>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACaza2_Statics::ClassParams = {
		&ACaza2::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACaza2_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACaza2_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACaza2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACaza2_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACaza2, 173324138);
	template<> GALAGA_USFX_API UClass* StaticClass<ACaza2>()
	{
		return ACaza2::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACaza2(Z_Construct_UClass_ACaza2, &ACaza2::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("ACaza2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACaza2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
