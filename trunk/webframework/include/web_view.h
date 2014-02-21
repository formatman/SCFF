#ifndef __WEB_SOLUTION_WEB_FRAMEWORK_VIEW_H__
#define __WEB_SOLUTION_WEB_FRAMEWORK_VIEW_H__

#include <stdint.h>
#include <map>
#include <list>
#include <string>

namespace web_solution{ namespace web_framework{

	class CWebViewTemplate;
	/**
	* @class CWebViewDict
	* @brief View�ֵ���
	*/
	class CWebViewDict 
	{
		friend class  CWebViewTemplate;
	public:
		/**
		* @fn explicit CWebViewDict(const std::string& name)
		* @brief ��ʽ���캯��
		* @param sName �ֵ�����(ֻ��Ϊ�˵��Է���)
		*/
		explicit CWebViewDict(const std::string& sName);
		~CWebViewDict();
		/**
		* @fn const std::string& Name()
		* @brief ��ȡ�ֵ�����
		* @return �ֵ�����(ֻ��Ϊ�˵��Է���)
		*/
		const std::string& Name();

	public:
		/**
		* @fn void SetValue(const std::string& sKey, const std::string& sVal)
		* @brief ����string���ֵ���(key-value��)
		*/
		void SetValue(const std::string& sKey, const std::string& sVal);
		void SetValue(const std::string& sKey, int8_t v);
		void SetValue(const std::string& sKey, int16_t v);
		void SetValue(const std::string& sKey, int32_t v);
		void SetValue(const std::string& sKey, int64_t v);
		void SetValue(const std::string& sKey, uint8_t v);
		void SetValue(const std::string& sKey, uint16_t v);
		void SetValue(const std::string& sKey, uint32_t v);
		void SetValue(const std::string& sKey, uint64_t v);
		/**
		* @fn void SetIntValue(const std::string& sKey, int iVal)
		* @brief ����int���ֵ���(key-value��)
		*/
		void SetIntValue(const std::string& sKey, int iVal);
		/**
		* @fn void SetMoney(const std::string& sKey, double val)
		* @brief ����money���ֵ���(key-value��)
		*/
		void SetMoney(const std::string& sKey, double val);
		/**
		* @fn CWebViewDict& AddSectionDictionary(const std::string section_name)
		* @brief ���һ��Section�ֵ�
		* @param sSectionName Section����
		* @return ����һ��ViewDict����(NULLΪʧ��),�ɱ���������SetValue�Լ�ShowSection�Ȳ���
		*/
		CWebViewDict* AddSectionDictionary(const std::string& sSectionName);
		/**
		* @fn void ShowSection(const std::string& sSectionName)
		* @brief �����ʾһ��Section�ֵ�
		* @param sSectionName Section����
		*/
		void ShowSection(const std::string& sSectionName);
		/**
		* @fn void SetValueAndShowSection(const std::string& sKey, const std::string& sVal, const std::string& sSectionName)
		* @brief �����ֶ�ֵ�Ƿ�ǿ��������ʾһ��Section�ֵ�(�ֶηǿ�������ʾSection,��������Section)
		* @param sKey �ֶ�����
		* @param sVal �ֶ�ֵ
		* @param sSectionName Section����
		* @return ����һ��ViewDict����,�ɱ���������SetValue�Լ�ShowSection�Ȳ���
		*/
		void SetValueAndShowSection(const std::string& sKey, const std::string& sVal, const std::string& sSectionName);
		/**
		* @fn void Dump(int indent = 0) const
		* @brief Dump���ֵ�
		* @param indent ÿ�������ַ�����(ȱʡΪ������)
		*/
		void Dump(int indent = 0) const;
		/**
		* @fn void DumpToString(std::string& sOut, int indent = 0) const
		* @brief Dump���ֵ䵽�ַ���
		* @param sOut Ŀ���ַ���
		* @param indent ÿ�������ַ�����(ȱʡΪ������)
		*/
		void DumpToString(std::string& sOut, int indent = 0) const;

		/**
		* @fn const std::string& Name()
		* @brief Clone
		* @return ��ʵ����ָ��
		*/
		//CWebViewDict* Clone();		

	protected:
		CWebViewDict();
		CWebViewDict(const CWebViewDict&);
		void operator=(const CWebViewDict&);

	protected:
		void* m_pDict;
		bool m_bRoot;
		std::list<CWebViewDict*> m_SubDictList;
	};

	/**
	* @class CWebViewTemplate
	* @brief Viewģ����
	*/
	class  CWebViewTemplate
	{
	public:
		/**
		* @enum Strip
		* @brief �����Stripѡ��
		*/
		enum Strip 
		{ 
			DO_NOT_STRIP, 
			STRIP_BLANK_LINES, 
			STRIP_WHITESPACE,
			NUM_STRIPS 
		};   
	public:
		virtual ~CWebViewTemplate();
		/**
		* @fn static CWebViewTemplate *GetTemplate(const std::string& sFileName, Strip strip = DO_NOT_STRIP)
		* @brief �Ӵ����ļ�����ģ��
		* @param sFileName �����ļ���
		* @param strip �����Stripѡ��@ref enum Strip
		* @return CWebViewTemplate����(NULLΪʧ��)
		*/
		static CWebViewTemplate* GetTemplate(const std::string& sFileName, Strip strip = DO_NOT_STRIP);
		const char *GetTemplateFileName() const;

		/**
		* @fn static CWebViewTemplate* StringToTemplate(const char* pszTplContent, Strip strip = DO_NOT_STRIP)
		* @brief ���ַ�������ת����ģ��
		* @param pszTplContent ��'\0'��β�ַ�������
		* @param strip �����Stripѡ��@ref enum Strip
		* @return CWebViewTemplate����(NULLΪʧ��)
		*/
		static CWebViewTemplate* StringToTemplate(const char* pszTplContent, Strip strip = DO_NOT_STRIP);

		/**
		* @fn static CWebViewTemplate* StringToTemplate(const std::string& sTplContent, Strip strip = DO_NOT_STRIP)
		* @brief ���ַ�������ת����ģ��
		* @param sTplContent STL String�����ַ�������
		* @param strip �����Stripѡ��@ref enum Strip
		* @return CWebViewTemplate����(NULLΪʧ��)
		*/
		static CWebViewTemplate* StringToTemplate(const std::string& sTplContent, Strip strip = DO_NOT_STRIP);

		/**
		* @fn static void ClearCache()
		* @brief ��������ڲ�cache,��������Template���
		*/
		static void ClearCache();

		/**
		* @fn static bool SetTemplateRootDirectory(const std::string& sDir)
		* @brief ����ģ���ļ��ĸ�·��
		* @param sDir ��·��
		* @return true�ɹ�, falseʧ��,·�����Ϸ�
		*/
		static bool SetTemplateRootDirectory(const std::string& sDir);
		static std::string GetTemplateRootDirectory();

		/**
		* @fn bool Expand(std::string& sOutBuffer, const CWebViewDict& rDict, bool bReset = true) const
		* @brief ��䲢չ��ģ��
		* @param sOutBuffer �������ݵ�buffer
		* @param rDict View�ֵ����
		* @return true�ɹ�, falseʧ��
		*/
		bool Expand(std::string& sOutBuffer, const CWebViewDict& rDict) const;

	public:
		
		CWebViewTemplate();

	protected:
		void* m_pTpl;
		static std::map<std::string, CWebViewTemplate> g_TplMap;
	};

	/**
	* @class CWebViewData
	* @brief View������,����Dict���û��Զ����������
	*/
	class CWebViewData
	{
	public:
		/**
		* @fn CWebViewDict& GetDict()
		* @brief ��ȡģ���ֵ����
		*/
		CWebViewDict& GetDict();

	public:
		void SetUserData(const std::string& sName, const std::string& sVal);
		void SetUserData(const std::string& sName, int8_t cVal);
		void SetUserData(const std::string& sName, int16_t wVal);
		void SetUserData(const std::string& sName, int32_t dwVal);
		void SetUserData(const std::string& sName, int64_t ddwVal);
		void SetUserData(const std::string& sName, uint8_t cVal);
		void SetUserData(const std::string& sName, uint16_t wVal);
		void SetUserData(const std::string& sName, uint32_t dwVal);
		void SetUserData(const std::string& sName, uint64_t ddwVal);

		int GetUserData(const std::string& sName, std::string& sVal);
		int GetUserData(const std::string& sName, int8_t& cVal);
		int GetUserData(const std::string& sName, int16_t& wVal);
		int GetUserData(const std::string& sName, int32_t& dwVal);
		int GetUserData(const std::string& sName, int64_t& ddwVal);
		int GetUserData(const std::string& sName, uint8_t& cVal);
		int GetUserData(const std::string& sName, uint16_t& wVal);
		int GetUserData(const std::string& sName, uint32_t& dwVal);
		int GetUserData(const std::string& sName, uint64_t& ddwVal);

		/* Cookie��� */
		void DelCookieVal(const std::string& sName);
		void UpdateCookieVal(const std::string& sName, const std::string& sVal, const std::string& sTime, const std::string& sDomain, bool bEncodeWithChn = true);
		void UpdateCookieVal2(const std::string& sName, const std::string& sVal, const std::string& sTime, const std::string& sDomain, const std::string& sEncodeType);
		void UpdateCookieVal(const std::string& sName, int iVal, const std::string& sTime, const std::string& sDomain, bool bEncodeWithChn = true);
		void UpdateCookieVal(const std::string& sName, uint32_t dwVal, const std::string& sTime, const std::string& sDomain, bool bEncodeWithChn = true);
		void UpdateCookieVal(const std::string& sName, int64_t ddwVal, const std::string& sTime, const std::string& sDomain, bool bEncodeWithChn = true);
		void UpdateCookieVal(const std::string& sName, uint64_t ddwVal, const std::string& sTime, const std::string& sDomain, bool bEncodeWithChn = true);
		
	public:
		bool OutputCookie();
		bool OutputCookie(std::string& sSetCookie);

	public:
		CWebViewData();

	private:
		void AddCookieVal(const std::string& sName, int iVal, const std::string& sTime, const std::string& sDomain);
		void AddCookieVal(const std::string& sName, uint32_t dwVal, const std::string& sTime, const std::string& sDomain);
		void AddCookieVal(const std::string& sName, int64_t ddwVal, const std::string& sTime, const std::string& sDomain);
		void AddCookieVal(const std::string& sName, uint64_t ddwVal, const std::string& sTime, const std::string& sDomain);
		void AddCookieVal(const std::string& sName, const std::string& sVal, const std::string& sTime, const std::string& sDomain);
		void AddCookieVal(const std::string& sName, const std::string& sVal, const std::string& sTime, const std::string& sDomain, const std::string& sEncodeType);
		void SetCookie(const char *name, const char *value, const char *expires, const char *path, const char *domain, short secure, const char *encode);
		void SetCookie(std::string& sOutput, const char *name, 
			const char *value, const char *expires, const char *path, const char *domain, short secure, const char *encode);
		
		void StringReplace(std::string & strBig, const std::string & strSrc, const std::string &strDst);
		char* UrlEncodeForCookie(char *sDest, const char *sSrc); 

	private:
		typedef struct tagCookie
		{
			bool bSet; // false-client�˴����ԭʼcookie; true-server�ظ�ie�ĸ���cookie
			std::string sTime;
			std::string sDomain;
			std::string sVal;
			std::string sEncodeType;
		} COOKIE_T;
		std::map<std::string, COOKIE_T> m_oCookieMap;
		CWebViewDict m_oDict;
		std::map<std::string, std::string> m_oUserStrDataMap;
		std::map<std::string, int64_t> m_oUserIntDataMap;
		std::map<std::string, uint64_t> m_oUserUIntDataMap;
		bool m_bEncodeWithChn;
	};

}}

#endif /// __WEB_SOLUTION_WEB_FRAMEWORK_VIEW_H__
