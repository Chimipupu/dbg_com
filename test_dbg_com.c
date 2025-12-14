/**
 * @file test_dbg_com.c
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief デバッグモニタ(dbg_com)のテスト
 * @version 0.1
 * @date 2025-12-14
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */
#include "dbg_com.h"

static void cmd_dummy(dbg_cmd_args_t *p_args);

// コマンドテーブル
const dbg_cmd_info_t g_cmd_tbl[] = {
//  | 短縮/フルコマンド文字列 | コールバック関数 | 最小引数 | 最大引数 | コマンドの説明分 |
    {"dm", "dummy",           &cmd_dummy,    0,          0,       "Dummy Cmd(for Debug)"},
};

// コマンドテーブルのコマンド数
size_t g_total_cmd = sizeof(g_cmd_tbl) / sizeof(g_cmd_tbl[0]);

static void cmd_dummy(dbg_cmd_args_t *p_args)
{
    printf("Dummy Cmd\n");
}

int main(void)
{
    dbg_com_config_t config;
    config.p_cmd_tbl = &g_cmd_tbl[0];
    config.total_cmd = g_total_cmd;
    dbg_com_init(&config);

    while (1)
    {
        dbg_com_main();
    }
}