// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/Escudo2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEscudo2() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_AEscudo2_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_AEscudo2();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveEscudo();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
// End Cross Module References
	void AEscudo2::StaticRegisterNativesAEscudo2()
	{
	}
	UClass* Z_Construct_UClass_AEscudo2_NoRegister()
	{
		return AEscudo2::StaticClass();
	}
	struct Z_Construct_UClass_AEscudo2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEscudo2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveEscudo,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEscudo2_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Escudo2.h" },
		{ "ModuleRelativePath", "Escudo2.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEscudo2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEscudo2>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEscudo2_Statics::ClassParams = {
		&AEscudo2::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEscudo2_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEscudo2_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEscudo2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEscudo2_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEscudo2, 3991481928);
	template<> GALAGA_USFX_API UClass* StaticClass<AEscudo2>()
	{
		return AEscudo2::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEscudo2(Z_Construct_UClass_AEscudo2, &AEscudo2::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("AEscudo2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEscudo2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
