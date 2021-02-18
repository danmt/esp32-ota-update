const express = require("express");

const app = express();

app.get("/api/firmware", (req, res) =>
  res.status(200).json({ hello: "world" })
);

app.listen(3000, () => console.log("server running on 3000"));
