# Message Templates

- All messages are sent in UTF-8 encoded JSON format
- Field names follow the lowercase + snake_case rule
- Additional fields may be added in the future considering expansion, so it is recommended to parse flexibly

## request.json

```json
{
  "command": "start",
  "id": 1
}
```

### key-value (request.json)

| key   | type    | description                           |
|----------|---------|--------------------------------|
| command  | string  | command to execute (e.g.  `"start"`, `"stop"`) |
| id       | int     | job id        |

## response.json

```json
{
  "success": true,
  "message": "Task completed successfully"
}
```

### key-value (response.json)

| key   | type     | description                          |
|----------|----------|-------------------------------|
| success  | bool  | command result (`true`/`false`) |
| message  | string   | result message     |
