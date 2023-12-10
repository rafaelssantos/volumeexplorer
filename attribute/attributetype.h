#ifndef ATTRIBUTETYPE_H
#define ATTRIBUTETYPE_H



namespace attribute {


enum AttributeType {
	ABSOLUTE_DEVIATION,
    CONTRAST,
	ENERGY,
	ENTROPY,
	GRADIENT,
	INTENSITY,
    INERTIA,
    KURTOSIS,
    LAPLACIAN,
    MEAN,
    SKEWNESS,
    STANDARD_DEVIATION,
    VARIANCE
};

typedef  enum AttributeType AttributeType;


}


#endif // ATTRIBUTETYPE_H
