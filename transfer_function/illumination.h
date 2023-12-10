#ifndef LIGHTPROP_H
#define LIGHTPROP_H




namespace transfer_function {
	struct Illumination {
            float ambientPower;
            float diffusePower;
            float specularPower;
            int shininess;
			bool enabled;
	};


	typedef struct Illumination Illumination;
}



#endif // LIGHTPROP_H
