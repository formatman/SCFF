#ifndef __WEB_SOLUTION_WEB_FRAMEWORK_SVC_CNTL_H__
#define __WEB_SOLUTION_WEB_FRAMEWORK_SVC_CNTL_H__

#include <stdint.h>
#include <assert.h>
#include <string>

namespace web_solution{ namespace web_framework{
	class CWebSvcCntl
	{
	public:
		void SetResult(uint32_t dwResult) { m_dwResult = dwResult; }
		uint32_t GetResult() const { return m_dwResult; }

		void SetUpdateTime(uint32_t dwVal) { m_dwUpdateTime = dwVal; }
		uint32_t GetUpdateTime() const { return m_dwUpdateTime; }

		void SetWebCacheExpireTime(uint32_t dwVal) { m_dwWebCacheExpireTime = dwVal; }
		uint32_t GetWebCacheExpireTime() const { return m_dwWebCacheExpireTime; }

		void SetBrowserCacheExpireTime(uint32_t dwVal) { m_dwBrowserCacheExpireTime = dwVal; }
		uint32_t GetBrowserCacheExpireTime() const { return m_dwBrowserCacheExpireTime; }

		void SetEtags(const char* pszVal, size_t nLen) { assert(pszVal); m_sEtags.assign(pszVal, nLen); }
		void SetEtags(const std::string& sVal) { m_sEtags = sVal; }
		const std::string& GetEtags() const { return m_sEtags; }

		void SetMimeType(const char* pszVal, size_t nLen) { assert(pszVal); m_sMimeType.assign(pszVal, nLen); }
		void SetMimeType(const std::string& sVal) { m_sMimeType = sVal; }
		const std::string& GetMimeType() const { return m_sMimeType; }

		void SetMimeEncoding(const char* pszVal, size_t nLen) { assert(pszVal); m_sMimeEncoding.assign(pszVal, nLen); }
		void SetMimeEncoding(const std::string& sVal) { m_sMimeEncoding = sVal; }
		const std::string& GetMimeEncoding() const { return m_sMimeEncoding; }

		void SetUseWebCache(uint8_t cVal) { m_cUseWebCache = cVal; }
		uint8_t GetUseWebCache() const { return m_cUseWebCache; }

		void SetContentEncoding(uint8_t cVal) { m_cContentEncoding = cVal; }
		uint8_t GetContentEncoding() const { return m_cContentEncoding; }

		void SetLocation(const char* pszVal, size_t nLen) { assert(pszVal); m_sLocation.assign(pszVal, nLen); }
		void SetLocation(const std::string& sVal) { m_sLocation = sVal; }
		const std::string& GetLocation() const { return m_sLocation; }

		void SetOutputHead(const char* pszVal, size_t nLen) { assert(pszVal); m_sOutputHead.assign(pszVal, nLen); }
		void SetOutputHead(const std::string& sVal) { m_sOutputHead = sVal; }
		std::string GetOutputHead() { 
			std::string headerInfo = "";

			if (!m_sMimeType.empty()){
				headerInfo += "Content-Type: " + m_sMimeType +"\n";
			}
			if (m_dwBrowserCacheExpireTime){
				// @TODO
				//headerInfo += "Expires: \n";
			}
			if (!m_sMimeEncoding.empty()){
				headerInfo += "Content-Encoding: " + m_sMimeEncoding +"\n";
			}
			if (!m_sEtags.empty()){
				headerInfo += "ETag: " + m_sEtags +"\n";
			}	
			if (!m_sOutputHead.empty()){
				headerInfo += m_sOutputHead +"\n";
			}			
			return headerInfo; 
		}

	private:
		uint32_t m_dwResult; ///< ҵ��ִ�н��
		uint32_t m_dwUpdateTime;	///< ���ݶ������ʱ��
        uint32_t m_dwWebCacheExpireTime;	///< ��Web Cache�еĹ���ʱ��
        uint32_t m_dwBrowserCacheExpireTime;	///< ��Browser Cache�еĹ���ʱ��
        std::string m_sEtags;	///< Etags����ֵ
        std::string m_sMimeType;	///< Mime����
        std::string m_sMimeEncoding;	///< Mime�еı�����Ϣ
        std::string m_sOutputHead;	///< ������ͷ
        uint8_t m_cUseWebCache;	///< �Ƿ�ʹ��web cache: 1) = 0 ��ʹ��web cache; 2) =1 ʹ��web cache
        uint8_t m_cContentEncoding;	///< �Ƿ��web ���ݽ��б���ѹ��: 1) = 0 ʹ��ȱʡ���뷽ʽ(Gzip); 2) =1 û��ʹ��web����ѹ��; 3) =2 ʹ��Gzip����ѹ������
        std::string m_sLocation;	///< �ض�����Ϣ
	};
}}

#endif /// __WEB_SOLUTION_WEB_FRAMEWORK_SVC_CNTL_H__

