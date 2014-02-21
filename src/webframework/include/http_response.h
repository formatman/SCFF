/**
 * @brief HttpӦ���༰�����л�������
 * 
 * @author Binqiang Huang(yota)
 * @date 2007.03.21
 */
#ifndef __WEB_SOLUTION_COMM_HTTP_RESPONSE_H__
#define __WEB_SOLUTION_COMM_HTTP_RESPONSE_H__

#include "serializable.h"

#include <stdint.h>
#include <assert.h>

namespace web_solution{ namespace comm{
    class CSOHttpResponse;

    class CHttpResponse
    {
        friend class CSOHttpResponse;

    public:
        CHttpResponse() : m_cProtocolVersion(0), 
            m_dwSeqNo(0), m_dwConnectionId(0), m_dwVhostId(0), m_dwRequestTime(0), 
            m_cMethodType(0), m_cProtocol(0), m_cConnection(0), m_dwResult(0), 
            m_dwUpdateTime(0), m_dwWebCacheExpireTime(0), m_dwBrowserCacheExpireTime(0), 
            m_cUseWebCache(0), m_cContentEncoding(0) 
        {
        }

		void Reset()
		{
			m_cProtocolVersion = 0;
			m_dwSeqNo = 0;
			m_dwConnectionId = 0;
			m_dwVhostId = 0;
			m_dwRequestTime = 0;
			m_cMethodType = 0;
			m_cProtocol = 0;
			m_cConnection = 0;
			m_dwResult = 0;
			m_dwUpdateTime = 0;
			m_dwWebCacheExpireTime = 0;
			m_dwBrowserCacheExpireTime = 0;
			m_cUseWebCache = 0;
			m_cContentEncoding = 0;
			m_cConnection = 0;	///< �������ͣ�1�� = 0 ��֧�ֳ����ӣ� 2�� = 1 ֧�ֳ�����
			m_cFrontServerType = 0;	///< ǰ��server����

			m_sUrl = "";	///< ���ʵ�url
			m_sAcceptEncoding = "";	///< ���ܱ��뷽ʽ
			m_sAcceptLanguage = "";	///< ��������
			m_sCookie = "";	///< cookie
			m_sHost = "";	///< ������
			m_sUserAgent = "";	///< �û�����
			m_sClientIp = "";	///< �û��ķ���ip
			m_sEtags = "";	///< Etags����ֵ
			m_sMimeType = "";	///< Mime����
			m_sMimeEncoding = "";	///< Mime�еı�����Ϣ
			m_sLocation = "";	///< �ض�����Ϣ

			m_sResponseContent = "";	///< Ӧ����������
		}

    public:
        void SetProtocolVersion(uint8_t cVal) { m_cProtocolVersion = cVal; }
        uint8_t GetProtocolVersion() const { return m_cProtocolVersion; }

        void SetSeqNo(uint32_t dwVal) { m_dwSeqNo = dwVal; }
        uint32_t GetSeqNo() const { return m_dwSeqNo; }

        void SetConnectionId(uint32_t dwVal) { m_dwConnectionId = dwVal; }
        uint32_t GetConnectionId() const { return m_dwConnectionId; }

        void SetVhostId(uint32_t dwVal) { m_dwVhostId = dwVal; }
        uint32_t GetVhostId() const { return m_dwVhostId; }        

        void SetRequestTime(uint32_t dwVal) { m_dwRequestTime = dwVal; }
        uint32_t GetRequestTime() const { return m_dwRequestTime; }

        void SetMethodType(uint8_t cVal) { m_cMethodType = cVal; }
        uint8_t GetMethodType() const { return m_cMethodType; }

        void SetProtocol(uint8_t cVal) { m_cProtocol = cVal; }
        uint8_t GetProtocol() const { return m_cProtocol; }

        void SetUrl(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sUrl.assign(pszVal, nLen); }
        void SetUrl(const std::string& sVal) { m_sUrl = sVal; }
        const std::string& GetUrl() const { return m_sUrl; }

        void SetAcceptEncoding(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sAcceptEncoding.assign(pszVal, nLen); }
        void SetAcceptEncoding(const std::string& sVal) { m_sAcceptEncoding = sVal; }
        const std::string& GetAcceptEncoding() const { return m_sAcceptEncoding; }

        void SetAcceptLanguage(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sAcceptLanguage.assign(pszVal, nLen); }
        void SetAcceptLanguage(const std::string& sVal) { m_sAcceptLanguage = sVal; }
        const std::string& GetAcceptLanguage() const { return m_sAcceptLanguage; }

        void SetConnection(uint8_t cVal) { m_cConnection = cVal; }
        uint8_t GetConnection() const { return m_cConnection; }

        void SetCookie(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sCookie.assign(pszVal, nLen); }
        void SetCookie(const std::string& sVal) { m_sCookie = sVal; }
        const std::string& GetCookie() const { return m_sCookie; }

        void SetHost(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sHost.assign(pszVal, nLen); }
        void SetHost(const std::string& sVal) { m_sHost = sVal; }
        const std::string& GetHost() const { return m_sHost; }

        void SetUserAgent(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sUserAgent.assign(pszVal, nLen); }
        void SetUserAgent(const std::string& sVal) { m_sUserAgent = sVal; }
        const std::string& GetUserAgent() const { return m_sUserAgent; }

        void SetClientIp(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sClientIp.assign(pszVal, nLen); }
        void SetClientIp(const std::string& sVal) { m_sClientIp = sVal; }
        const std::string& GetClientIp() const { return m_sClientIp; }

        void SetResult(uint32_t dwVal) { m_dwResult = dwVal; }
        uint32_t GetResult() const { return m_dwResult; }

        void SetUpdateTime(uint32_t dwVal) { m_dwUpdateTime = dwVal; }
        uint32_t GetUpdateTime() const { return m_dwUpdateTime; }

        void SetWebCacheExpireTime(uint32_t dwVal) { m_dwWebCacheExpireTime = dwVal; }
        uint32_t GetWebCacheExpireTime() const { return m_dwWebCacheExpireTime; }

        void SetBrowserCacheExpireTime(uint32_t dwVal) { m_dwBrowserCacheExpireTime = dwVal; }
        uint32_t GetBrowserCacheExpireTime() const { return m_dwBrowserCacheExpireTime; }

        void SetEtags(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sEtags.assign(pszVal, nLen); }
        void SetEtags(const std::string& sVal) { m_sEtags = sVal; }
        const std::string& GetEtags() const { return m_sEtags; }

        void SetMimeType(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sMimeType.assign(pszVal, nLen); }
        void SetMimeType(const std::string& sVal) { m_sMimeType = sVal; }
        const std::string& GetMimeType() const { return m_sMimeType; }

        void SetMimeEncoding(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sMimeEncoding.assign(pszVal, nLen); }
        void SetMimeEncoding(const std::string& sVal) { m_sMimeEncoding = sVal; }
        const std::string& GetMimeEncoding() const { return m_sMimeEncoding; }

        void SetUseWebCache(uint8_t cVal) { m_cUseWebCache = cVal; }
        uint8_t GetUseWebCache() const { return m_cUseWebCache; }

        void SetContentEncoding(uint8_t cVal) { m_cContentEncoding = cVal; }
        uint8_t GetContentEncoding() const { return m_cContentEncoding; }

        void SetFrontServerType(uint8_t cVal) { m_cFrontServerType = cVal;}
        uint8_t GetFrontServerType() const { return m_cFrontServerType; }

        void SetLocation(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sLocation.assign(pszVal, nLen); }
        void SetLocation(const std::string& sVal) { m_sLocation = sVal; }
        const std::string& GetLocation() const { return m_sLocation; }

        void SetResponseContent(const char* pszVal, uint32_t nLen) { assert(pszVal); m_sResponseContent.assign(pszVal, nLen); }
        void SetResponseContent(const std::string& sVal) { m_sResponseContent = sVal; }
        const std::string& GetResponseContent() const { return m_sResponseContent; }

    public:
        enum
        {
            NOT_USE_WEB_CACHE = 0,
            USE_WEB_CACHE = 1,
            

            PROCESS_SUCC = 0,
            PROCESS_FAIL = 1,

            DEFAULT_ENCODING = 0,
            NO_ENCODING = 1,
            USE_GZIP_ENCODING = 2,
        };

    private:
        uint8_t m_cProtocolVersion; ///< ͨ��Э��汾

        uint32_t m_dwSeqNo;	///< ����������к�
        uint32_t m_dwConnectionId;	///< ���ӱ�ʶ
        uint32_t m_dwVhostId;	///< ����������ʶ
        uint32_t m_dwRequestTime;	///< ǰ�˽��յ������ʱ�䣬��λΪs
        uint8_t m_cMethodType;	///< ��������
        uint8_t m_cProtocol;	///< Э�����ͣ�1��= 0 http 0.9Э��汾�� 2��= 1 http 1.0 Э��汾�� 3��= 2 http 1.1Э��汾
        std::string m_sUrl;	///< ���ʵ�url
        std::string m_sAcceptEncoding;	///< ���ܱ��뷽ʽ
        std::string m_sAcceptLanguage;	///< ��������
        uint8_t m_cConnection;	///< �������ͣ�1�� = 0 ��֧�ֳ����ӣ� 2�� = 1 ֧�ֳ�����
        std::string m_sCookie;	///< cookie
        std::string m_sHost;	///< ������
        std::string m_sUserAgent;	///< �û�����
        std::string m_sClientIp;	///< �û��ķ���ip
        uint32_t m_dwResult;	///< ������
        uint32_t m_dwUpdateTime;	///< ���ݶ������ʱ��
        uint32_t m_dwWebCacheExpireTime;	///< ��Web Cache�еĹ���ʱ��
        uint32_t m_dwBrowserCacheExpireTime;	///< ��Browser Cache�еĹ���ʱ��
        std::string m_sEtags;	///< Etags����ֵ
        std::string m_sMimeType;	///< Mime����
        std::string m_sMimeEncoding;	///< Mime�еı�����Ϣ
        uint8_t m_cUseWebCache;	///< �Ƿ�ʹ��web cache: 1) = 0 ��ʹ��web cache; 2) =1 ʹ��web cache
        uint8_t m_cContentEncoding;	///< �Ƿ��web ���ݽ��б���ѹ��: 1) = 0 ʹ��ȱʡ���뷽ʽ(Gzip); 2) =1 û��ʹ��web����ѹ��; 3) =2 ʹ��Gzip����ѹ������
        uint8_t m_cFrontServerType;	///< ǰ��server����
        std::string m_sLocation;	///< �ض�����Ϣ

        std::string m_sResponseContent;	///< Ӧ����������
    };

    class CSOHttpResponse: public ISerializable
    {
    public:
        virtual bool Serialize(CByteStreamNetwork& bs);
        virtual void Dump(std::ostream& os);

    public:
        void SetSerializeObject(CHttpResponse* pResp)
        {
            m_pSerializeObject = pResp;
        }

    private:
        CHttpResponse* m_pSerializeObject;
    };
}}

#endif /// __WEB_SOLUTION_COMM_HTTP_RESPONSE_H__


