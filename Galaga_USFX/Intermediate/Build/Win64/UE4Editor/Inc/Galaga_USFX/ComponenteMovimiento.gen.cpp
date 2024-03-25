// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX/ComponenteMovimiento.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeComponenteMovimiento() {}
// Cross Module References
	GALAGA_USFX_API UClass* Z_Construct_UClass_UComponenteMovimiento_NoRegister();
	GALAGA_USFX_API UClass* Z_Construct_UClass_UComponenteMovimiento();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX();
// End Cross Module References
	void UComponenteMovimiento::StaticRegisterNativesUComponenteMovimiento()
	{
	}
	UClass* Z_Construct_UClass_UComponenteMovimiento_NoRegister()
	{
		return UComponenteMovimiento::StaticClass();
	}
	struct Z_Construct_UClass_UComponenteMovimiento_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovimientoSig_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovimientoSig;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UComponenteMovimiento_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UComponenteMovimiento_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ComponenteMovimiento.h" },
		{ "ModuleRelativePath", "ComponenteMovimiento.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UComponenteMovimiento_Statics::NewProp_MovimientoSig_MetaData[] = {
		{ "Category", "ComponenteMovimiento" },
		{ "ModuleRelativePath", "ComponenteMovimiento.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UComponenteMovimiento_Statics::NewProp_MovimientoSig = { "MovimientoSig", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UComponenteMovimiento, MovimientoSig), METADATA_PARAMS(Z_Construct_UClass_UComponenteMovimiento_Statics::NewProp_MovimientoSig_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UComponenteMovimiento_Statics::NewProp_MovimientoSig_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UComponenteMovimiento_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UComponenteMovimiento_Statics::NewProp_MovimientoSig,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UComponenteMovimiento_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComponenteMovimiento>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UComponenteMovimiento_Statics::ClassParams = {
		&UComponenteMovimiento::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UComponenteMovimiento_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UComponenteMovimiento_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UComponenteMovimiento_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UComponenteMovimiento_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UComponenteMovimiento()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UComponenteMovimiento_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UComponenteMovimiento, 1204492234);
	template<> GALAGA_USFX_API UClass* StaticClass<UComponenteMovimiento>()
	{
		return UComponenteMovimiento::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UComponenteMovimiento(Z_Construct_UClass_UComponenteMovimiento, &UComponenteMovimiento::StaticClass, TEXT("/Script/Galaga_USFX"), TEXT("UComponenteMovimiento"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UComponenteMovimiento);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
