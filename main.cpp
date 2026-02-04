#include <iostream>
#include <fstream>
#include <pqxx/pqxx>
#include <string>
#include <iomanip>

int main() {
    try {
        // 1. 连接数据库 (使用你刚改好的 123456)
        pqxx::connection C("dbname=postgres user=postgres password=123456 host=127.0.0.1 port=5432");
        pqxx::work W(C);

        // 2. 创建网页文件
        std::ofstream htmlFile("index.html");

        // 3. 写入网页头部和 CSS 样式
        htmlFile << R"(
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <title>OW 英雄胜率榜 (S20)</title>
    <style>
        body { background-color: #1a1a1a; color: #eee; font-family: sans-serif; padding: 40px; }
        h2 { color: #f99e1a; border-left: 5px solid #f99e1a; padding-left: 15px; }
        table { width: 100%; border-collapse: collapse; margin-top: 20px; box-shadow: 0 0 20px rgba(0,0,0,0.5); }
        th, td { padding: 15px; border: 1px solid #333; text-align: left; }
        th { background-color: #333; color: #f99e1a; text-transform: uppercase; letter-spacing: 1px; }
        .Tank { color: #00aeff; font-weight: bold; }
        .Damage { color: #ff4444; font-weight: bold; }
        .Support { color: #00ff88; font-weight: bold; }
        tr:hover { background-color: #252525; }
        .hot { background-color: rgba(249, 158, 26, 0.1); border-left: 3px solid #f99e1a; }
    </style>
</head>
<body>
    <h2>🚀 守望先锋 S20 实时数据 (C++ 后端驱动)</h2>
    <table>
        <thead><tr><th>英雄名称</th><th>职责</th><th>当前胜率</th></tr></thead>
        <tbody>
)";

        // 4. 查询数据
        pqxx::result R = W.exec("SELECT name, role, win_rate FROM heroes ORDER BY win_rate DESC");

        // 5. 循环把数据库数据写进 HTML 表格
        for (auto row : R) {
            float winRate = row[2].as<float>();
            std::string rowClass = (winRate > 53.0) ? " class='hot'" : "";

            htmlFile << "            <tr" << rowClass << ">\n"
                     << "                <td>" << row[0].c_str() << "</td>\n"
                     << "                <td class='" << row[1].c_str() << "'>" << row[1].c_str() << "</td>\n"
                     << "                <td>" << std::fixed << std::setprecision(1) << winRate << "%</td>\n"
                     << "            </tr>\n";
        }

        htmlFile << "</tbody></table></body></html>";
        htmlFile.close();

        std::cout << "✅ 完美成功！网页 index.html 已生成。" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "❌ 错误: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}