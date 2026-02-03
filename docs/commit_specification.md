# Git commit 信息规范

一个规范的 git commit 包括:

- 包含**标签**的标题(必须)
- 简略的描述(可选)

简略规范参考下方 `commit_specification.md` 文档, 详细参考[规范](https://www.conventionalcommits.org/en/v1.0.0/)
> 此文档帮助规范提交信息
>
> Author: Junjie Yu

## 推荐模板

标准模板

```bash
<标签>[<(范围)>]: <标题>

<简略描述>
```

其中 *简略描述* , *模块* 可以省略

### 示例1

```bash
feat: 新增XX功能 

- 第一部分XX(如果较多可用列表来罗列)
- 第二部分XX
- ...
```

或者

```bash
feat(module_name): 新增XX功能 

- 第一部分XX(如果较多可用列表来罗列)
- 第二部分XX
- ...
```

### 示例2

```bash
feat(module_name): 新增XX功能
```

或者

```bash
feat: 新增XX功能
```

### 实际用法截图

![commit_specification](https://yjj001-1316573526.cos.ap-nanjing.myqcloud.com/yysjls/commit_specification.png)

## 标签类型

如下表所示:

| 类型         | 含义                                    | 示例                                  |
| ------------ | --------------------------------------- | ------------------------------------- |
| **feat**     | 新功能                                  | `feat: 新增用户注册接口`              |
| **fix**      | 修复 bug                                | `fix: 修复密码校验错误`               |
| **refactor** | 重构(不涉及功能/bug)                    | `refactor: 重构数据库查询逻辑`        |
| **doc**      | 文档修改                                | `doc: 更新 README 使用说明`           |
| **style**    | 代码风格(格式化,空格,分号等),不影响逻辑 | `style: 格式化XX文件`                 |
| **test**     | 增加/修改测试用例                       | `test: 补充用户注册接口的单元测试`    |
| **chore**    | 杂项(构建过程,工具配置,依赖更新)        | `chore: 更新依赖到 Django 5.0`        |
| **perf**     | 性能优化                                | `perf: 提升查询效率,减少SQL执行次数`  |
| **build**    | 构建系统或外部依赖相关                  | `build: 升级webpack到5.9.0`           |
| **ci**       | CI/CD 配置                              | `ci: 添加GitHub Actions自动测试`      |
| **revert**   | 回滚某次提交                            | `revert: 回滚 feat: 新增用户注册接口` |
