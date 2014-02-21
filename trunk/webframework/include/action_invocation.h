/**
 * @brief Action Invocation��
 * ����������Actionʵ���Ͷ��������ʵ���б���invoke()�����ж�interceptor list��action��result��ģ�����ν��е���
 * ���������Ĵ�����Ӧ
 *
 * �ڽӿ����Ե����ķ�ʽ�ṩ�������δ��������ٵĿ���
 * 
 * @author Binqiang Huang(yota)
 * @date 2007.07.17
 */
#ifndef __WEB_SOLUTION_WEB_FRAMEWORK_ACTION_INVOCATION_H__
#define __WEB_SOLUTION_WEB_FRAMEWORK_ACTION_INVOCATION_H__

#include "interceptor_factory.h"
#include "action_params.h"
#include <list>

namespace web_solution{ namespace web_framework{
    class CActionInvocation
    {
    public:
        /// Ҫʹ�õ���������setter�ķ�ʽע�룬����ActionInvocation���������������ٺ���Դ���ͷ�
        bool SetInterceptor(CInterceptor* pInterceptor, void* pParameter);

        /// ������Ƕ�ڿ���ڱ�׼�ṩ��������
        ///
        /// ���ṩ�ı�׼�������У�
        ///     TimerInterceptor ��ʱͳ��������;
        /// 
        bool SetStdInterceptorByName(const std::string& sInterceptorName, void* pParameter);
       
        /// ������־ģ��logger����
        void SetLoggerName(std::string& sLoggerName);

        /// ��ȡ��־ģ��logger����
        const std::string& GetLoggerName() const;     

		const std::string& GetLastErrMsg() const;

    public:
		static CActionInvocation* GetInstance();
		int ParseActionName(
				uint8_t cMethodType,
				const std::string& sFileName, 
				const std::string& sQueryString, 
				const std::string& sPostInfo, 
				const std::string& sContentType,
				const std::string& sCookies,
				std::string& sControllerName, 
				std::string& sActionName, 
				CActionParams& oActionParams);
		int InvokeInterceptorBefore(void* pParam);
		int InvokeInterceptorAfter(void* pParam);

		int InvokeInterceptor(bool bBefore); // �Ѿ��ϳ�,ռλ�Ա��ϰ汾��adaptor���Ա���ͨ��

        ~CActionInvocation();

	private:
		void ParseHeader(const std::string& data, std::string& disposition, std::string& name, std::string& filename, std::string& type);
		int ParseMIME(const std::string& data, std::string& name, std::string& value);
		int ParseMIME2(const std::string& data, std::string& name, std::string& value, std::string& filename);
		int DoMultiPartParse(const std::string& sPostInfo, const std::string& sContentType, CActionParams& oActionParam);
		int DoStandardParse(std::string& sParamPairs, CActionParams& oActionParam);
		int DoParseCookie(const std::string& sCookie, CActionParams& oActionParam);

    private:
        static CActionInvocation* m_pInstance;
        std::list<CInterceptor*> m_oInterceptorList;
        std::string m_sLoggerName;
        CInterceptorFactory m_oInterceptorFactory;
        std::string m_sLastErrMsg;
    };
}}

#endif /// __WEB_SOLUTION_WEB_FRAMEWORK_ACTION_INVOCATION_H__


