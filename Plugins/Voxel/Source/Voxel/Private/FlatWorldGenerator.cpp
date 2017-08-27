// Copyright 2017 Phyronnaz

#include "VoxelPrivatePCH.h"
#include "FlatWorldGenerator.h"

float UFlatWorldGenerator::GetDefaultValue_Implementation(FIntVector Position)
{
	return (Position.Z == Height) ? 0 : ((Position.Z > Height) ? MaxValue : MinValue);
}

FColor UFlatWorldGenerator::GetDefaultColor_Implementation(FIntVector Position)
{
	for (auto Layer : Layers)
	{
		if (Layer.Start <= Position.Z && Position.Z < Layer.Start + Layer.Height)
		{
			return Layer.Color.ToFColor(true);
		}
	}
	return DefaultColor.ToFColor(true);
}