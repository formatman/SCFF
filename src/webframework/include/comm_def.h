/**
 * @brief һЩ�����Ķ���
 * 
 * @author Binqiang Huang(yota)
 * @date 2007.03.21
 */
#ifndef __WEB_SOLUTION_COMM_COMM_DEF_H__
#define __WEB_SOLUTION_COMM_COMM_DEF_H__

namespace web_solution{ namespace comm{
    /// ͨ�ŵ���Ϣ����
    #define WEBSERVER_MSG_TYPE  0x1

    #define CACHEMGR_MSG_TYPE  0x2

    #define CONNECTOR_MSG_TYPE  0x3

    /// ֧�ֵ����Э��汾��
    #define HTTP_REQUEST_VERSION  0x01

    /// ǰ��web server����
    #define FRONT_WEBSVR_TYPE_APACHE 0x1

    #define FRONT_WEBSVR_TYPE_LW_WEBSERVER 0x2

    /// ����WebӦ�ÿ�����������汾
    /// ǰ��λ��ʾǰ��web server�汾���м���λ��ʾweb container�汾������λ��ʾweb framework�汾
    /// �磺"Tencent Web Server(TWS) 2.1.1.0.1.0" ��ʾǰ��webserver 2.1 version;
    /// web container 1.0 version; web framework 0.1 version
    #define WEB_SOLUTION_VERSION "Tencent Web Server(TWS) 2.1.1.0.0.1"

    /// HTTP ����Ӧ���뼰��Ҫ����
    #define PROCESS_SUCC_RESULT_CODE 200
    #define PROCESS_SUCC_RESULT_CODE_DESCRIPTION "OK"

    #define PARTIAL_CONTENT_RESULT_CODE 206
    #define PARTIAL_CONTENT_RESULT_CODE_DESCRIPTION "Partial Content"


    #define FOUND_RESULT_CODE 302
    #define FOUND_RESULT_CODE_DESCRIPTION "Found"

    #define NOT_MODIFIED_RESULT_CODE 304
    #define NOT_MODIFIED_RESULT_CODE_DESCRIPTION "Not Modified"


    #define BAD_REQUEST_RESULT_CODE 400
    #define BAD_REQUEST_RESULT_CODE_DESCRIPTION "Bad Request"

    #define NOT_FOUND_RESULT_CODE 404
    #define NOT_FOUND_RESULT_CODE_DESCRIPTION "Not Found"

    #define TIMEOUT_RESULT_CODE 408
    #define TIMEOUT_RESULT_CODE_DESCRIPTION "Request Timeout"


    #define SERVER_INTERNAL_FAIL_RESULT_CODE 500
    #define SERVER_INTERNAL_FAIL_RESULT_CODE_DESCRIPTION "Internal Error"

    #define NOT_IMPLEMENTED_RESULT_CODE 501
    #define NOT_IMPLEMENTED_RESULT_CODE_DESCRIPTION "Not Implemented"

    #define SERVER_OVERLOAD_RESULT_CODE 503
    #define SERVER_OVERLOAD_RESULT_CODE_DESCRIPTION "Service Temporarily Overloaded"
}}

#endif ///__WEB_SOLUTION_COMM_COMM_DEF_H__


