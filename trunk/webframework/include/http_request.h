/**
 * @brief Http�����༰�����л�������
 * 
 * @author Binqiang Huang(yota)
 * @date 2007.03.21
 */
#ifndef __WEB_SOLUTION_COMM_HTTP_REQUEST_H__
#define __WEB_SOLUTION_COMM_HTTP_REQUEST_H__

#include <assert.h>
#include "serializable.h"
#include <map>

const uint32_t HTTP_REQUEST_VERSION_1 = 101;	/*�汾�Ŵ�101��ʼ����Ϊ֮ǰ�õ���99*/

namespace web_solution{ namespace comm{
    class CSOHttpRequest;

    class CHttpRequest
    {
        friend class CSOHttpRequest;

    public:
        CHttpRequest() : m_cProtocolVersion(0),
            m_dwSeqNo(0), m_dwConnectionId(0), m_dwRequestTime(0), 
            m_cMethodType(0), m_cProtocol(0), m_cConnection(0), 
            m_dwIfModifySince(0), m_dwClientPort(0)
        { 
            memset(m_acSetFlags, 0, sizeof(m_acSetFlags)); 
        }

		void Reset()
		{
			m_cProtocolVersion = 0;
			m_dwSeqNo = 0;
			m_dwConnectionId = 0;
			m_dwRequestTime = 0;
			m_cMethodType = 0;
			m_cProtocol = 0;
			m_cConnection = 0;
			m_dwIfModifySince = 0;
			m_dwClientPort = 0;
			m_cFrontServerType = 0;	///< ǰ��server����
			m_dwContentLength = 0;	///< ���ݳ���

			m_sUrl = "";	///< ���ʵ�url
			m_sAcceptEncoding = "";	///< ���ܱ��뷽ʽ
			m_sAcceptLanguage = "";	///< ��������
			m_sCookie = "";	///< cookie
			m_sHost = "";	///< ������
			m_sFileName = "";	///< Ҫ�����ļ���
			m_sReferer = "";	///< ���õ�ַ
			m_sUserAgent = "";	///< �û�����
			m_sClientIp = "";	///< �û��ķ���ip
			m_sNoneMatchInfo = "";	///< none-match ��Ϣ
			m_sQueryString = "";	///< ��ѯ�ֶ�
			m_sPostInfo = "";	///< Post��Ϣ
			m_sPathInfo = "";	///< ����·����Ϣ
			m_sAccept = "";	///< ��������			
		}

        bool IsAllSet() const 
        { 
            for(uint32_t i = 0; i < sizeof(m_acSetFlags); ++i) 
            { 
                if(m_acSetFlags[i] == 0) 
                {
                    return false; 
                }
            } 

            return true; 
        }

    public:
        void SetProtocolVersion(uint8_t cVal) { m_cProtocolVersion = cVal; }
        uint8_t GetProtocolVersion() const { return m_cProtocolVersion; }

        void SetSeqNo(uint32_t dwVal) { m_dwSeqNo = dwVal; m_acSetFlags[3] = 1; }
        uint32_t GetSeqNo() const { return m_dwSeqNo; }

        void SetConnectionId(uint32_t dwVal) { m_dwConnectionId = dwVal; m_acSetFlags[4] = 1; }
        uint32_t GetConnectionId() const { return m_dwConnectionId; }

        void SetRequestTime(uint32_t dwVal) { m_dwRequestTime = dwVal; m_acSetFlags[5] = 1; }
        uint32_t GetRequestTime() const { return m_dwRequestTime; }

        void SetMethodType(uint8_t cVal) { m_cMethodType = cVal; m_acSetFlags[6] = 1; }
        uint8_t GetMethodType() const { return m_cMethodType; }

        void SetProtocol(uint8_t cVal) { m_cProtocol = cVal; m_acSetFlags[7] = 1; }
        uint8_t GetProtocol() const { return m_cProtocol; }

        void SetUrl(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sUrl.assign(pszVal, nLen); m_acSetFlags[8] = 1; }
        void SetUrl(const std::string& sVal) { m_sUrl = sVal; m_acSetFlags[8] = 1; }
        const std::string& GetUrl() const { return m_sUrl; }

        void SetAcceptEncoding(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sAcceptEncoding.assign(pszVal, nLen); m_acSetFlags[9] = 1; }
        void SetAcceptEncoding(const std::string& sVal) { m_sAcceptEncoding = sVal; m_acSetFlags[9] = 1; }
        const std::string& GetAcceptEncoding() const { return m_sAcceptEncoding; }

        void SetAcceptLanguage(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sAcceptLanguage.assign(pszVal, nLen); m_acSetFlags[10] = 1; }
        void SetAcceptLanguage(const std::string& sVal) { m_sAcceptLanguage = sVal; m_acSetFlags[10] = 1; }
        const std::string& GetAcceptLanguage() const { return m_sAcceptLanguage; }

        void SetConnection(uint8_t cVal) { m_cConnection = cVal; m_acSetFlags[11] = 1; }
        uint8_t GetConnection() const { return m_cConnection; }

        void SetCookie(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sCookie.assign(pszVal, nLen); m_acSetFlags[12] = 1; }
        void SetCookie(const std::string& sVal) { m_sCookie = sVal; m_acSetFlags[12] = 1; }
        const std::string& GetCookie() const { return m_sCookie; }

        void SetHost(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sHost.assign(pszVal, nLen); m_acSetFlags[13] = 1; }
        void SetHost(const std::string& sVal) { m_sHost = sVal; m_acSetFlags[13] = 1; }
        const std::string& GetHost() const { return m_sHost; }

        void SetFileName(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sFileName.assign(pszVal, nLen);}
        void SetFileName(const std::string& sVal) { m_sFileName = sVal;}
        const std::string& GetFileName() const { return m_sFileName; }

        void SetReferer(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sReferer.assign(pszVal, nLen); m_acSetFlags[14] = 1; }
        void SetReferer(const std::string& sVal) { m_sReferer = sVal; m_acSetFlags[14] = 1; }
        const std::string& GetReferer() const { return m_sReferer; }

        void SetIfModifySince(uint32_t dwVal) { m_dwIfModifySince = dwVal; m_acSetFlags[15] = 1; }
        uint32_t GetIfModifySince() const { return m_dwIfModifySince; }

        void SetUserAgent(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sUserAgent.assign(pszVal, nLen); m_acSetFlags[16] = 1; }
        void SetUserAgent(const std::string& sVal) { m_sUserAgent = sVal; m_acSetFlags[16] = 1; }
        const std::string& GetUserAgent() const { return m_sUserAgent; }

        void SetClientIp(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sClientIp.assign(pszVal, nLen); m_acSetFlags[17] = 1; }
        void SetClientIp(const std::string& sVal) { m_sClientIp = sVal; m_acSetFlags[17] = 1; }
        const std::string& GetClientIp() const { return m_sClientIp; }

        void SetClientPort(uint32_t dwVal) { m_dwClientPort = dwVal; }
        uint32_t GetClientPort() const { return m_dwClientPort; }

        void SetNoneMatchInfo(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sNoneMatchInfo.assign(pszVal, nLen); m_acSetFlags[18] = 1; }
        void SetNoneMatchInfo(const std::string& sVal) { m_sNoneMatchInfo = sVal; m_acSetFlags[18] = 1; }
        const std::string& GetNoneMatchInfo() const { return m_sNoneMatchInfo; }

        void SetQueryString(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sQueryString.assign(pszVal, nLen); m_acSetFlags[19] = 1; }
        void SetQueryString(const std::string& sVal) { m_sQueryString = sVal; m_acSetFlags[19] = 1; }
        const std::string& GetQueryString() const { return m_sQueryString; }

        void SetPostInfo(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sPostInfo.assign(pszVal, nLen); m_acSetFlags[20] = 1; }
        void SetPostInfo(const std::string& sVal) { m_sPostInfo = sVal; m_acSetFlags[20] = 1; }
        const std::string& GetPostInfo() const { return m_sPostInfo; }

        void SetFrontServerType(uint8_t cVal) { m_cFrontServerType = cVal;}
        uint8_t GetFrontServerType() const { return m_cFrontServerType; }

        void SetPathInfo(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sPathInfo.assign(pszVal, nLen);}
        void SetPathInfo(const std::string& sVal) { m_sPathInfo = sVal;}
        const std::string& GetPathInfo() const { return m_sPathInfo; }

        void SetContentLength(uint32_t dwVal) { m_dwContentLength = dwVal;}
        uint32_t GetContentLength() const { return m_dwContentLength; }

        void SetAccept(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sAccept.assign(pszVal, nLen);}
        void SetAccept(const std::string& sVal) { m_sAccept = sVal; }
        const std::string& GetAccept() const { return m_sAccept; }	

    public:
        enum
        {
            HTTP_PROCOTOL_09 = 0,
            HTTP_PROCOTOL_10 = 1,
            HTTP_PROCOTOL_11 = 2,

            UNKNOWN_METHOD_TYPE = 0,
            GET_METHOD_TYPE = 1,
            HEAD_METHOD_TYPE = 2,
            POST_METHOD_TYPE = 3,

            NO_KEEP_ALIVE = 0,
            KEEP_ALIVE = 1,
        };

    protected:
        uint8_t m_acSetFlags[21];

        uint8_t m_cProtocolVersion; ///< ͨ��Э��汾

        uint32_t m_dwSeqNo;	///< ����������к�
        uint32_t m_dwConnectionId;	///< ���ӱ�ʶ
        uint32_t m_dwRequestTime;	///< ǰ�˽��յ������ʱ�䣬��λΪs
        uint8_t m_cMethodType;	///< ��������: 1) = 1 GET�� 2�� = 2 HEAD�� 3) = 3 POST
        uint8_t m_cProtocol;	///< Э�����ͣ�1��= 0 http 0.9Э��汾�� 2��= 1 http 1.0 Э��汾�� 3��= 2 http 1.1Э��汾
        std::string m_sUrl;	///< ���ʵ�url
        std::string m_sAcceptEncoding;	///< ���ܱ��뷽ʽ
        std::string m_sAcceptLanguage;	///< ��������
        uint8_t m_cConnection;	///< �������ͣ�1�� = 0 ��֧�ֳ����ӣ� 2�� = 1 ֧�ֳ�����
        std::string m_sCookie;	///< cookie
        std::string m_sHost;	///< ������
        std::string m_sFileName;	///< Ҫ�����ļ���
        std::string m_sReferer;	///< ���õ�ַ
        uint32_t m_dwIfModifySince;	///< �ϴθ���ʱ��
        std::string m_sUserAgent;	///< �û�����
        std::string m_sClientIp;	///< �û��ķ���ip
        uint32_t m_dwClientPort;	///< �û��ķ��ʶ˿�
        std::string m_sNoneMatchInfo;	///< none-match ��Ϣ
        std::string m_sQueryString;	///< ��ѯ�ֶ�
        std::string m_sPostInfo;	///< Post��Ϣ

        uint8_t m_cFrontServerType;	///< ǰ��server����
        std::string m_sPathInfo;	///< ����·����Ϣ
        uint32_t m_dwContentLength;	///< ���ݳ���
        std::string m_sAccept;	///< ��������

    };

	class CHttpRequest2 : public CHttpRequest
	{
        friend class CSOHttpRequest2;
	public:
		void Reset()
		{
			CHttpRequest::Reset();
			m_sContentType = "";
			m_HTTP_X_FORWARDED_FOR = "";
			m_HTTP_X_REAL_IP = "";
			m_HTTP_X_ORIGINAL_HOST = "";
			m_HTTP_X_ORIGINAL_URL = "";
			m_HTTP_X_ARR_LOG_ID = "";
		}

        void SetContentType(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sContentType.assign(pszVal, nLen);}
        void SetContentType(const std::string& sVal) { m_sContentType = sVal; }
        const std::string& GetContentType() const { return m_sContentType; }

		void SetHTTP_X_FORWARDED_FOR(const char* pszVal, uint32_t nLen) { assert(pszVal); m_HTTP_X_FORWARDED_FOR.assign(pszVal, nLen);}
		void SetHTTP_X_FORWARDED_FOR(const std::string& sVal) { m_HTTP_X_FORWARDED_FOR = sVal;}
		const std::string& GetHTTP_X_FORWARDED_FOR() const { return m_HTTP_X_FORWARDED_FOR;} 

		void SetHTTP_X_REAL_IP(const char* pszVal, uint32_t nLen) { assert(pszVal); m_HTTP_X_REAL_IP.assign(pszVal, nLen);}
		void SetHTTP_X_REAL_IP(const std::string& sVal) { m_HTTP_X_REAL_IP = sVal;}
		const std::string& GetHTTP_X_REAL_IP() const { return m_HTTP_X_REAL_IP;} 

		void SetHTTP_X_ORIGINAL_HOST(const char* pszVal, uint32_t nLen) { assert(pszVal); m_HTTP_X_ORIGINAL_HOST.assign(pszVal, nLen);}
		void SetHTTP_X_ORIGINAL_HOST(const std::string& sVal) { m_HTTP_X_ORIGINAL_HOST = sVal;}
		const std::string& GetHTTP_X_ORIGINAL_HOST() const { return m_HTTP_X_ORIGINAL_HOST;} 

		void SetHTTP_X_ORIGINAL_URL(const char* pszVal, uint32_t nLen) { assert(pszVal); m_HTTP_X_ORIGINAL_URL.assign(pszVal, nLen);}
		void SetHTTP_X_ORIGINAL_URL(const std::string& sVal) { m_HTTP_X_ORIGINAL_URL = sVal;}
		const std::string& GetHTTP_X_ORIGINAL_URL() const { return m_HTTP_X_ORIGINAL_URL;} 

		void SetHTTP_X_ARR_LOG_ID(const char* pszVal, uint32_t nLen) { assert(pszVal); m_HTTP_X_ARR_LOG_ID.assign(pszVal, nLen);}
		void SetHTTP_X_ARR_LOG_ID(const std::string& sVal) { m_HTTP_X_ARR_LOG_ID = sVal;}
		const std::string& GetHTTP_X_ARR_LOG_ID() const { return m_HTTP_X_ARR_LOG_ID;} 

	protected:
		std::string m_sContentType;
		/*
        	* add by anthonywei@tencent.com �����Զ����ͷ��
		*/
		std::string m_HTTP_X_FORWARDED_FOR;	
		std::string m_HTTP_X_REAL_IP;
		std::string m_HTTP_X_ORIGINAL_HOST;
		std::string m_HTTP_X_ORIGINAL_URL;
		std::string m_HTTP_X_ARR_LOG_ID;
				
	};

    class CSOHttpRequest: public ISerializable
    {
    public:
        virtual bool Serialize(CByteStreamNetwork& bs);
        virtual void Dump(std::ostream& os);

    public:
        void SetSerializeObject(CHttpRequest* pReq)
        {
            m_pSerializeObject = pReq;
        }

    private:
        CHttpRequest* m_pSerializeObject;
    };

    class CSOHttpRequest2: public CSOHttpRequest
    {
    public:
        virtual bool Serialize(CByteStreamNetwork& bs);
        virtual void Dump(std::ostream& os);

    public:
        void SetSerializeObject(CHttpRequest2* pReq)
        {
			CSOHttpRequest::SetSerializeObject(pReq);
            m_pSerializeObject2 = pReq;
        }

    private:
        CHttpRequest2* m_pSerializeObject2;
    };
}}

#endif /// __WEB_SOLUTION_COMM_HTTP_REQUEST_H__


