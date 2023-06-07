import React from "react";
import "./game-panel.css";
import { Card } from "../index";

const GamePanel = () => {
  return (
    <section className="game-panel">
      <h3 className="sr-only">Peças do Jogo</h3>
      <div id="game">
        <Card name="angular" /> 
        <Card name="html" /> 
        <Card name="javascript" />
        <Card name="vue" /> 
        <Card name="react" /> 
        <Card name="ember" />
      </div>
    </section>
  );
};

export default GamePanel;
