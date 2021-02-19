const express = require("express");

const app = express();

let version = 0;

app.get("/api/firmware", (req, res) =>
  res.status(200).json({ version: version++ })
);

app.listen(3000, () => console.log("server running on 3000"));
