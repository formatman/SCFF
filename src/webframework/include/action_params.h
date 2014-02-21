
#ifndef __WEB_SOLUTION_WEB_FRAMEWORK_ACTION_PARAMS_H__
#define __WEB_SOLUTION_WEB_FRAMEWORK_ACTION_PARAMS_H__

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <stdint.h>

namespace web_solution{ namespace web_framework{
	class CActionInvocation;

#define ECC_TWS_ASYNC_KEY "EccTwsAsyncKey"
#define ECC_TWS_ASYNC_MAGIC_DATA "EccTwsAsyncMagicData"
#define ECC_TWS_ASYNC_BACKEND_RSP "EccTwsAsyncBackendRsp"

	/**
	 * @class CActionParams
	 * @brief ҳ�������ȡ��
	 */
	class CActionParams
	{
		friend class CActionInvocation;
	public:
		/**
		 * @fn GetVal(const std::string& sName, std::string& sVal,uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char* sErrMsg = NULL) const;
		 * @brief ��ȡ�ַ���
		 * @param sName ֵ�Եļ�ֵ
		 * @param sVal  ֵ�Ե�����
		 * @param dwMaxLen �ַ�����󳤶��޶�(0��ʾ���޶�)
		 * @param dwMinLen �ַ�����С�����޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */
		int GetVal(const std::string& sName, std::string& sVal, 
				uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

		/**
		 * @fn GetVal(const std::string& sName, std::string& sVal, bool bNeedAntiXss = false, uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char* sErrMsg = NULL) const;
		 * @brief ��ȡ�ַ���
		 * @param sName ֵ�Եļ�ֵ
		 * @param sVal  ֵ�Ե�����
		 * @param bNeedAntiXss �Ƿ���Ҫ����antixss����
		 * @param dwMaxLen �ַ�����󳤶��޶�(0��ʾ���޶�)
		 * @param dwMinLen �ַ�����С�����޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */
		int GetVal(const std::string& sName, std::string& sVal, bool bNeedAntiXss, 
				uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

		/**
		 * @fn GetVal(const std::string& sName, std::string& sVal, bool bNeedAntiXss, uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char* sErrMsg = NULL) const;
		 * @brief ��ȡ�ַ���
		 * @param sName ֵ�Եļ�ֵ
		 * @param sVal  ֵ�Ե�����
		 * @param bNeedAntiXss �Ƿ���Ҫ����antixss����
		 * @param sConf antixss����ʹ�õ������ļ�
		 * @param dwMaxLen �ַ�����󳤶��޶�(0��ʾ���޶�)
		 * @param dwMinLen �ַ�����С�����޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */
		int GetVal(const std::string& sName, std::string& sVal, bool bNeedAntiXss, const std::string &sConf,
				uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
				

		
		/**
		 * @fn GetVal(const std::string& sName, char* psValBuf, uint32_t dwValBufLen, uint32_t dwMaxLen, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char* sErrMsg = NULL) const;
		 * @brief ��ȡ�ַ���
		 * @param sName ֵ�Եļ�ֵ
		 * @param psValBuf  ֵ��Buf
		 * @param dwValBufLen  ֵ��BufLen
		 * @param dwMaxLen �ַ�����󳤶��޶�(0��ʾ���޶�)
		 * @param dwMinLen �ַ�����С�����޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */
		int GetVal(const std::string& sName, char* psValBuf, uint32_t dwValBufLen,
				uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
	

		/**
		 * @fn GetRawVal(const std::string& sName, std::string& sVal,uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡ������RAW��
		 * @param sName ֵ�Եļ�ֵ
		 * @param sVal  ֵ�Ե�����
		 * @param dwMaxLen ������RAW����󳤶��޶�(0��ʾ���޶�)
		 * @param dwMinLen ������RAW����С�����޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */
		int GetRawVal(const std::string& sName, std::string& sVal, 
				uint32_t dwMaxLen = 0, uint32_t dwMinLen = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

		/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡuint8_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param cVal ֵ�Ե�����
		 * @param cMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param cMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, uint8_t& cVal, 			
				uint8_t cMax = 0, uint8_t cMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

		/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡuint16_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param wVal ֵ�Ե�����
		 * @param wMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param wMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, uint16_t& wVal, 			
				uint16_t wMax = 0, uint16_t wMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

		/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡuint32_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param dwVal ֵ�Ե�����
		 * @param dwMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param dwMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, uint32_t& dwVal, 			
				uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
				
		/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡuint64_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param ddwVal ֵ�Ե�����
		 * @param ddwMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param ddwMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, uint64_t& ddwVal, 			
				uint64_t ddwMax = 0, uint64_t ddwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

		/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡint8_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param cVal ֵ�Ե�����
		 * @param cMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param cMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, int8_t& cVal, 			
				int8_t cMax = 0, int8_t cMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
	
		/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡint16_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param wVal ֵ�Ե�����
		 * @param wMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param wMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, int16_t& wVal, 			
				int16_t wMax = 0, int16_t wMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

		/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡint32_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param iVal ֵ�Ե�����
		 * @param iMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param iMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, int32_t& iVal, 			
				int32_t iMax = 0, int32_t iMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

	/**
		 * @fn GetVal(const std::string& sName, uint32_t& dwVal,uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;
		 * @brief ��ȡint64_t������ֵ
		 * @param sName ֵ�Եļ�ֵ
		 * @param ddwVal ֵ�Ե�����
		 * @param ddwMax ��ֵ����޶�(0��ʾ���޶�)
		 * @param ddwMin ��ֵ��С�޶�(0��ʾ���޶�)
		 * @param pszPrompt ����ʱ�����ʾ��ǰ׺,�����ڻ�ȡGetLastErrMsg()ʱ�õ����Ի�������
		 * @param sErrMsg[] ����û��ṩ����buffer,��ὫGetLastErrMsg()�����ݸ�����
		 */		
		int GetVal(const std::string& sName, int64_t& ddVal, 			
				int64_t ddwMax = 0, int64_t ddMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;


		int GetVal(const std::string& sName, std::vector<std::string>& vecVal) const;
		/*
		int GetVal(const std::string& sName, uint8_t& cVal) const;
		int GetVal(const std::string& sName, uint16_t& wVal) const;
		int GetVal(const std::string& sName, uint64_t& ddwVal) const;
		int GetVal(const std::string& sName, int8_t& cVal) const;
		int GetVal(const std::string& sName, int16_t& wVal) const;
		int GetVal(const std::string& sName, int32_t& dwVal) const;
		int GetVal(const std::string& sName, int64_t& ddwVal) const;
		*/

		int GetIntMoney(const std::string& sName, uint32_t& dwMoney, uint32_t dwMax = 0, uint32_t dwMin = 0, const char *pszPrompt = NULL, char sErrMsg[] = NULL) const;

	public:
		int GetCookieVal(const std::string& sName, std::string& sVal) const;
		int GetCookieVal(const std::string& sName, uint8_t& cVal) const;
		int GetCookieVal(const std::string& sName, uint16_t& wVal) const;
		int GetCookieVal(const std::string& sName, uint32_t& dwVal) const;
		int GetCookieVal(const std::string& sName, uint64_t& ddwVal) const;
		int GetCookieVal(const std::string& sName, int8_t& cVal) const;
		int GetCookieVal(const std::string& sName, int16_t& wVal) const;
		int GetCookieVal(const std::string& sName, int32_t& dwVal) const;
		int GetCookieVal(const std::string& sName, int64_t& ddwVal) const;
		
	public:
		void Reset();
		void Dump(std::ostream& os);
		void AddVal(const std::string& sName, const std::string& sVal);
		const char* GetLastErrMsg() const;
		// antixss ����
		int DoAntiXss(std::string& sInput) const;
		int DoAntiXss(std::string& sInput, const std::string &sConf) const;
		void AddCookiePair(const std::string& sName, const std::string& sVal); // For CActionInvocation

	private:
		void StringReplace(std::string & strBig, const std::string & strSrc, const std::string &strDst);
		bool IsNumber(const std::string& sVal) const;
		bool IsMoney(const std::string& sMoney) const;
		bool IsPostCode(const std::string& sPostCode) const;
		// ȥ���Ƿ��ַ��Ͱ������
		std::string CleanChineseString(const char *pszRawString, uint32_t dwLength) const;

	private:
		typedef struct tagParam
		{
			std::vector<std::string> vecVal;
		} PARAM_T;

		typedef struct tagCookie
		{
			bool bSet; // false-client�˴����ԭʼcookie; true-server�ظ�ie�ĸ���cookie
			std::string sTime;
			std::string sDomain;
			std::string sVal;
		} COOKIE_T;

	private:	
		std::map<std::string, PARAM_T> m_oParamsMap;
		std::map<std::string, COOKIE_T> m_oCookieMap;
		char m_sErrMsg[128];

	private:
		int GetParam(const std::string& sName, PARAM_T** ppParam) const;
	};
}}

#endif /* __WEB_SOLUTION_WEB_FRAMEWORK_ACTION_PARAMS_H__ */

