import "./assets/styles/App.css";
import {
  ControlPanel,
  Footer,
  Header,
  GamePanel,
  } from "./components";
  
function App() {
  return (
    <div id="container">
      <Header/>
      <div className="main-content">
        <ControlPanel/>
        <GamePanel/>
      </div>
      <Footer/>
    </div>
  );
}

export default App;