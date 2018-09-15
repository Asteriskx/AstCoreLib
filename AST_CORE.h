#ifndef __AST_CORE_H__
#define __AST_CORE_H__

// string クラス模擬実装
typedef struct {
    char *m_data;       // 文字列
    size_t m_capacity;  // 最大容量
    size_t m_size;      // 文字数
} String;

#endif