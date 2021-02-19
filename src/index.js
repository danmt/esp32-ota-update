const express = require("express");
const path = require("path");

const app = express();

let version = 0;

app.get("/api/firmware", (_, res) =>
  res.status(200).download(path.join(__dirname, "./firmware.bin"))
);

app.listen(3000, () => console.log("server running on 3000"));
