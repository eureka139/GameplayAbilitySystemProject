// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/EnemyInterface.h"
#include "Character/AuraCharacterBase.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	AAuraEnemy();

	/* Enemy Interface */

	virtual void HighlightActor() override;

	virtual void UnHighlighsActor() override;
	
	/* Enemy Interface */


	
	/* Combat Interface */

	virtual int32 GetPlayerLevel() override;

	/* Combat Interface */

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignatrue OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignatrue OnMaxHealthChanged;
	

protected:

	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="CharacterClassDefaults")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

};
