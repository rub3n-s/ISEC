import { useState } from "react";
import "./assets/styles/App.css";
import { ControlPanel, Footer, Header, GamePanel } from "./components";

function App() {
  const [gameStarted, setGameStarted] = useState(false);
  const [selectedLevel, setSelectedLevel] = useState("0");

  const handleGameStart = () => (gameStarted === true ? setGameStarted(false) : setGameStarted(true));

  const handleLevelChange = (event) => {
    const { value } = event.currentTarget;
    setSelectedLevel(value);
  };

  return (
    <div id="container">
      <Header />
      <div className="main-content">
        <ControlPanel
          gameStarted={gameStarted}
          onGameStart={handleGameStart}
          selectedLevel={selectedLevel}
          onLevelChange={handleLevelChange}
        />
        <GamePanel />
      </div>
      <Footer />
    </div>
  );
}

export default App;
