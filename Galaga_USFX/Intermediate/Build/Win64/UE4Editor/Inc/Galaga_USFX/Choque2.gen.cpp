// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/Choque2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChoque2() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_AChoque2_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_AChoque2();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveChoque();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
// End Cross Module References
	void AChoque2::StaticRegisterNativesAChoque2()
	{
	}
	UClass* Z_Construct_UClass_AChoque2_NoRegister()
	{
		return AChoque2::StaticClass();
	}
	struct Z_Construct_UClass_AChoque2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChoque2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveChoque,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChoque2_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Choque2.h" },
		{ "ModuleRelativePath", "Choque2.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChoque2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChoque2>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChoque2_Statics::ClassParams = {
		&AChoque2::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AChoque2_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChoque2_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChoque2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChoque2_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChoque2, 1282566478);
	template<> GALAGA_USFX_API UClass* StaticClass<AChoque2>()
	{
		return AChoque2::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChoque2(Z_Construct_UClass_AChoque2, &AChoque2::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("AChoque2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChoque2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
