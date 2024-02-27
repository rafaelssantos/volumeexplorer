#ifndef RENDERINGSETTINGS_H
#define RENDERINGSETTINGS_H


#include <cuda_runtime.h>
#include "rendering/renderingspecs.h"
#include "transfer_function/interpolation.h"
#include "transfer_function/illumination.h"



namespace settings {

	class RenderingSettings {
		public:
			static RenderingSettings& instance();

			void load();

			void save();

			float rotationDegree() const;

			void setRotationDegree(float degree);

			float step() const;

			void setStep(float step);

			unsigned maxNumberOfSteps() const;

			void setMaxNumberOfSteps(unsigned numberOfSteps);

			float maxOpacity() const;

			void setMaxOpacity(float max_opacity);

			const dim3 &blockDim() const;

			void setBlockDim(unsigned x, unsigned y = 1, unsigned z = 1);

			void setBlockDim(const dim3& blockDim);

            transfer_function::Interpolation interpolation() const;

            void setInterpolation(transfer_function::Interpolation interpolation);

			void setZoomIncrement(float increment);

			float zoomIncrement() const;

            void setIllumEnabled(bool enabled);

            bool illumEnabled() const;

            void setIllumAmbientPower(float power);

            float illumAmbientPower() const;

            void setIllumDiffusePower(float power);

            float illumDiffusePower() const;

            void setIllumSpecularPower(float power);

            float illumSpecularPower() const;

            void setIllumShininess(int shininess);

            int illumShininess() const;

			const rendering::RenderingSpecs& specs() const;

            void setHQEnabled(bool enabled);

            bool HQEnabled() const;

			const transfer_function::Illumination& illumination() const;

            void setDevSyncronizeEnable(bool enabled);

            bool devSyncronizeEnabled() const;


		private:
			RenderingSettings();

			virtual ~RenderingSettings();



		private:
			dim3 m_blockDim;
            transfer_function::Interpolation m_interpolation;
			transfer_function::Illumination m_illumination;
			rendering::RenderingSpecs m_specs;
			float m_rotationDegree;
            bool m_devSyncronize;

            dim3 m_HQBlockDim;
            transfer_function::Interpolation m_HQInterpolation;
            transfer_function::Illumination m_HQIllumination;
            rendering::RenderingSpecs m_HQSpecs;
            float m_HQRotationDegree;
            bool m_HQEnabled;
            bool m_HQDevSyncronize;
	};



}



#endif // RENDERINGSETTINGS_H
