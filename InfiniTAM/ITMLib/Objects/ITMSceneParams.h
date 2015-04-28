// Copyright 2014 Isis Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../Objects/ITMIntrinsics.h"
#include "../Objects/ITMImage.h"

namespace ITMLib
{
	namespace Objects
	{
		/** \brief
		    Stores parameters of a scene like voxel size
		*/
		class ITMSceneParams
		{
		public:
			/// Size of a voxel, usually given in meters.
			float voxelSize;
			/** @{ */
			/** \brief
			    Fallback parameters: consider only parts of the
			    scene from @p viewFrustum_min in front of the camera
			    to a distance of @p viewFrustum_max. Usually the
			    actual depth range should be determined
			    automatically by a ITMLib::Engine::ITMVisualisationEngine.
			*/
			float viewFrustum_min, viewFrustum_max;
			/** @} */
			/** \brief
			    Encodes the width of the band of the truncated
			    signed distance transform that is actually stored
			    in the volume. This is again usually specified in
			    meters. The resulting width in voxels is @ref mu
			    divided by @ref voxelSize.
			*/
			float mu;
			/** \brief
			    Up to @ref maxW observations per voxel are averaged.
			    Beyond that a sliding average is computed.
			*/
			int maxW;

      //0.02f, 100, 0.005f, 0.2f, 3.0f
			ITMSceneParams(float mu, int maxW, float voxelSize,
				float viewFrustum_min, float viewFrustum_max)
			{
				this->mu = mu;
				this->maxW = maxW;
				this->voxelSize = voxelSize;
				this->viewFrustum_min = viewFrustum_min; this->viewFrustum_max = viewFrustum_max;
			}

			explicit ITMSceneParams(const ITMSceneParams *sceneParams) { this->SetFrom(sceneParams); }

			void SetFrom(const ITMSceneParams *sceneParams)
			{
				this->voxelSize = sceneParams->voxelSize;
				this->viewFrustum_min = sceneParams->viewFrustum_min;
				this->viewFrustum_max = sceneParams->viewFrustum_max;
				this->mu = sceneParams->mu;
				this->maxW = sceneParams->maxW;
			}
		};
	}
}
