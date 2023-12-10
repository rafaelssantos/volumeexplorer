#ifndef TFMEMMANAGER_H
#define TFMEMMANAGER_H



#include "transferfunction.cuh"



namespace transfer_function {


class TFMemManager {
public:
	static TFMemManager& instance();

    TransferFunction* cloneToDev(const TransferFunction* hostTransferFunction);

	void freeDevice(TransferFunction* devTransferFunction);

	void freeHost(TransferFunction* hostTransferFunction);

	void memcpyColors(TransferFunction* devTransferFunction, TransferFunction *hostTransferFunction);

	void memcpySettings(TransferFunction* devTransferFunction, TransferFunction *hostTransferFunction);

	void memcpyNormalsFromBuffer(TransferFunction* hostTransferFunction);



private:
	TFMemManager();

	virtual ~TFMemManager();

    TransferFunction m_swapBuffer;



private:
	TFMemManager(const TFMemManager&) = delete;
	void operator=(const TFMemManager&) = delete;
};


}




#endif // TFMEMMANAGER_H
