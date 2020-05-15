#pragma once
#include "BnInteractionType.generated.h"

UENUM(BlueprintType)
enum class EBnInteractionType : uint8
{
    Toggle,
    Slide,
    Hold
};