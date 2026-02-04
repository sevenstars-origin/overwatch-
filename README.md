# 守望先锋 S20 数据看板项目 (C++ & PostgreSQL)

## 🚀 项目成就
- 打通了从 **PostgreSQL (Docker)** 到 **C++ 后端** 再到 **HTML/CSS 前端** 的完整闭环。
- 实现了 45 位英雄数据的动态抓取与可视化展示。

---


### 1. 数据库永久化与自启动
为了避免每次开机手动运行容器，我实施了 Docker 自动重启策略：
```bash
# 设置容器始终自动重启
sudo docker update --restart=always my_postgres

# 确保 Docker 服务随系统启动
sudo systemctl enable docker.service