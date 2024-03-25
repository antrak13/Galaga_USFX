// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/Nave_Enemiga.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNave_Enemiga() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANave_Enemiga_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_ANave_Enemiga();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_UComponenteMovimiento_NoRegister();
// End Cross Module References
	void ANave_Enemiga::StaticRegisterNativesANave_Enemiga()
	{
	}
	UClass* Z_Construct_UClass_ANave_Enemiga_NoRegister()
	{
		return ANave_Enemiga::StaticClass();
	}
	struct Z_Construct_UClass_ANave_Enemiga_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mallaNaveEnemiga_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mallaNaveEnemiga;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ComponenteMovimiento_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ComponenteMovimiento;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANave_Enemiga_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANave_Enemiga_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Nave_Enemiga.h" },
		{ "ModuleRelativePath", "Nave_Enemiga.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_mallaNaveEnemiga_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Nave_Enemiga.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_mallaNaveEnemiga = { "mallaNaveEnemiga", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANave_Enemiga, mallaNaveEnemiga), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_mallaNaveEnemiga_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_mallaNaveEnemiga_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_ComponenteMovimiento_MetaData[] = {
		{ "Category", "Nave_Enemiga" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Nave_Enemiga.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_ComponenteMovimiento = { "ComponenteMovimiento", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANave_Enemiga, ComponenteMovimiento), Z_Construct_UClass_UComponenteMovimiento_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_ComponenteMovimiento_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_ComponenteMovimiento_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANave_Enemiga_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_mallaNaveEnemiga,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANave_Enemiga_Statics::NewProp_ComponenteMovimiento,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANave_Enemiga_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANave_Enemiga>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANave_Enemiga_Statics::ClassParams = {
		&ANave_Enemiga::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANave_Enemiga_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANave_Enemiga_Statics::PropPointers),
		0,
		0x009000A5u,
		METADATA_PARAMS(Z_Construct_UClass_ANave_Enemiga_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANave_Enemiga_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANave_Enemiga()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANave_Enemiga_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANave_Enemiga, 3777623191);
	template<> GALAGA_USFX_API UClass* StaticClass<ANave_Enemiga>()
	{
		return ANave_Enemiga::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANave_Enemiga(Z_Construct_UClass_ANave_Enemiga, &ANave_Enemiga::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("ANave_Enemiga"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANave_Enemiga);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
