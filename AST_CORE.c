#include "AST_CORE.h"

// string となりえる何か
typedef String string;

// コンストラクタの代用版
static void string()
{
    char[] val;
    val = (char[])malloc(sizeof(char[]));

    m_capacity = m_size = 0;
    m_data = val[m_size + 1];
    m_data[0] = '\0';

    // リソース解放
    free(val);
}

// (num,'x')
static void string(const size_t num, const char c)
{
    char[] val;
    val = (char[])malloc(sizeof(char[]));

    m_capacity = m_size = num;
    m_data = val[m_size + 1];

    for (size_t i = 0; i < m_size; ++i) { m_data[i] = c; }
    
    m_data[m_size] = '\0';

    // リソース解放
    free(val);
}

 // char* c
static void string(const char *c)
{
    char[] val;
    val = (char[])malloc(sizeof(char[]));

    m_capacity = m_size = strlen(c);
    m_data = val[m_size + 1];
    
    strcpy(m_data, c);

    // リソース解放
    free(val);
}

 // char* fmt, char* l
static void string(const char *fmt, const char *c)
{
    char[] val;
    val = (char[])malloc(sizeof(char[]));

    m_capacity = m_size = c - fmt;
    m_data = val[m_size + 1];
    strncpy(m_data, fmt, m_size);
    m_data[m_size] = '\0';

    // リソース解放
    free(val);
}

// コピーコンストラクタ版
static void string(const string &s)
{
    char[] val;
    val = (char[])malloc(sizeof(char[]));

    m_capacity = s.m_capacity;
    m_size = s.m_size;
    m_data = val[m_size + 1];

    strcpy(m_data, s.m_data);

    // リソース解放
    free(val);
}