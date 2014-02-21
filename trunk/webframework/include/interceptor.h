/**
 * @brief ������������
 * ����������ԭ����������������״̬�ģ���ֻ�ɵ���CActionInvocation�ṩ��public�����ӿ�
 * 
 * @author Binqiang Huang(yota)
 * @date 2007.07.17
 */
#ifndef __WEB_SOLUTION_WEB_FRAMEWORK_INTERCEPTOR_H__
#define __WEB_SOLUTION_WEB_FRAMEWORK_INTERCEPTOR_H__

#include <string>

namespace web_solution{ namespace web_framework{
    class CActionInvocation;

    class CInterceptor
    {
    public:
        /// ��������������Http���󱻴���ǰ�����ã���Ҫ����һЩ��ʼ������
        ///
        /// pParameter: Ϊ��������ʼ��ʱ��Ҫ�õ���һЩ�������ɴ���һ���࣬���ڷ����ж������ǿ������ת��
        /// ͨ������£����������������ƣ�m_sInterceptorName��������־���ٶ�λ
        virtual bool Init(void* pParameter)
        {
            return true;
        }

        //// ��Ҫ����һЩ��Դ�ͷŹ���
        virtual void Destroy()
        {
            return;
        }

        /// ��ҵ����ǰ��ִ������У�鴦��
        virtual int InterceptBeforeProcess(void* pParameter)
        {
            return OK;
        }

        /// ��ҵ�����ִ������У�鴦��
        virtual int InterceptAfterProcess(void* pParameter)
        {
            return OK;
        }

        virtual ~CInterceptor()
        {
        }

        /// ��ȡ����������
        std::string& GetName()
        {
            return m_sInterceptorName;
        }

    public:
        enum INTERCEPTOR_RETURN_TYPE
        {
		    SUCCESS = 0,                /// ����SUCCESS,����ɹ�,������ִ����������������
		    
            OK = 1,                     /// ����OK,����ɹ�,�������ú���������������

		    FAIL = 2,                   /// ����FAIL,����ʧ�ܣ������ٽ�����һ������

            INPUT_FAIL = 3,             /// ����INPUT_FAIL,���������������󣬽����ٽ�����һ������

            LOGIN_FAIL = 4,             /// ����LOGIN_FAIL,��Ҫ�����û���¼�������ٽ�����һ������
        };

    protected:
        std::string m_sInterceptorName;
    };
}}

#endif /// __WEB_SOLUTION_WEB_FRAMEWORK_INTERCEPTOR_H__


