// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/NaveChoque.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveChoque() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveChoque_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANaveChoque();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANave_Enemiga();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
// End Cross Module References
	void ANaveChoque::StaticRegisterNativesANaveChoque()
	{
	}
	UClass* Z_Construct_UClass_ANaveChoque_NoRegister()
	{
		return ANaveChoque::StaticClass();
	}
	struct Z_Construct_UClass_ANaveChoque_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveChoque_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANave_Enemiga,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveChoque_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "NaveChoque.h" },
		{ "ModuleRelativePath", "NaveChoque.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveChoque_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveChoque>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveChoque_Statics::ClassParams = {
		&ANaveChoque::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ANaveChoque_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveChoque_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveChoque()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveChoque_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveChoque, 1843002957);
	template<> GALAGA_USFX_API UClass* StaticClass<ANaveChoque>()
	{
		return ANaveChoque::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveChoque(Z_Construct_UClass_ANaveChoque, &ANaveChoque::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("ANaveChoque"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveChoque);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
