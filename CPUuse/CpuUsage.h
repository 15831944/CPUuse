/////////////////////////////////////////////////////////////////////////////
// 类名：CCpuUsage
// 功能：CPU利用率接口声明部分(服务器端)
// 说明：提供三个接口涵数：
//       IsShellSystemType()用来检测系统版本;
//		 CpuUsage2000()来完成NT/2000下CPU利用率;
//		 CpuUsage9x()来完成9x下CPU利用率;
// 作者：徐景周(johnny Xu, xujingzhou2016@gmail.com)
// 组织：未来工作室(Future Studio)
// 日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
#ifndef __CPUUSAGE_H_
#define __CPUUSAGE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCpuUsage
class ATL_NO_VTABLE CCpuUsage : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCpuUsage, &CLSID_CpuUsage>,
	public ISupportErrorInfo,
	public IDispatchImpl<ICpuUsage, &IID_ICpuUsage, &LIBID_CPUUSELib>
{
public:
	CCpuUsage()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CPUUSAGE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCpuUsage)
	COM_INTERFACE_ENTRY(ICpuUsage)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ICpuUsage
public:
	STDMETHOD(CpuUsage2000)(/*[out,retval]*/long* plResult);
	STDMETHOD(CpuUsage9x)(/*[out,retval]*/long *plResult);
	STDMETHOD(IsShellSystemType)(/*[out,retval]*/BSTR* pbstrSysType);

	STDMETHODIMP CCpuUsage::GetOSVersion(/*[out,retval]*/int *plMajor, int *plMinor);
};

#endif //__CPUUSAGE_H_
