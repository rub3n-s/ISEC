/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.example;

import java.io.File;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.AfterAll;
import static org.junit.jupiter.api.Assertions.*;
import org.owasp.dependencycheck.Engine;
import org.owasp.dependencycheck.analyzer.AnalysisPhase;
import org.owasp.dependencycheck.dependency.Dependency;
import org.owasp.dependencycheck.utils.Settings;

/**
 * Test cases for CustomAnalyzer
 */
public class CustomAnalyzerTest {
    
    Settings settings = null;
	
    public CustomAnalyzerTest() {
    }
    
    @BeforeAll
    public static void setUpClass() {
    }
    
    @AfterAll
    public static void tearDownClass() {
    }
    
    @BeforeEach
    public void setUp() {
        settings = new Settings();
    }

    @AfterEach
    public void tearDown() {
        settings.cleanup();
    }

    /**
     * Test of accept method, of class CustomAnalyzer.
     */
    @Test
    public void testAccept() {
        File pathname = new File("test.file");
        CustomAnalyzer instance = new CustomAnalyzer();
        boolean expResult = true;
        boolean result = instance.accept(pathname);
        assertEquals(expResult, result);
    }

    /**
     * Test of analyze method, of class CustomAnalyzer.
     */
    @Test
    public void testAnalyze() throws Exception {
        //The engine is generally null for most analyzer test cases but can be instantiated if needed.
        Engine engine = null;
        CustomAnalyzer instance = new CustomAnalyzer();
        instance.initialize(settings);
        instance.prepare(engine);
		
        File file = new File(CustomAnalyzer.class.getClassLoader().getResource("test.file").toURI().getPath());
        Dependency dependency = new Dependency(file);

        //TODO uncomment the following line and add assertions against the dependency.
        //instance.analyze(dependency, engine);
    }

    /**
     * Test of getName method, of class CustomAnalyzer.
     */
    @Test
    public void testGetName() {
        CustomAnalyzer instance = new CustomAnalyzer();
        String expResult = "CustomAnalyzer";
        String result = instance.getName();
        assertEquals(expResult, result);
    }

    /**
     * Test of getAnalysisPhase method, of class CustomAnalyzer.
     */
    @Test
    public void testGetAnalysisPhase() {
        CustomAnalyzer instance = new CustomAnalyzer();
        AnalysisPhase expResult = AnalysisPhase.INFORMATION_COLLECTION;
        AnalysisPhase result = instance.getAnalysisPhase();
        assertEquals(expResult, result);
    }

    /**
     * Test of initialize method, of class CustomAnalyzer.
     */
    @Test
    public void testInitialize() throws Exception {
        CustomAnalyzer instance = new CustomAnalyzer();
        instance.initialize(settings);
    }

    /**
     * Test of close method, of class CustomAnalyzer.
     */
    @Test
    public void testClose() throws Exception {
        CustomAnalyzer instance = new CustomAnalyzer();
        instance.close();
    }

    /**
     * Test of supportsParallelProcessing method, of class CustomAnalyzer.
     */
    @Test
    public void testSupportsParallelProcessing() {
        CustomAnalyzer instance = new CustomAnalyzer();
        boolean expResult = true;
        boolean result = instance.supportsParallelProcessing();
        assertEquals(expResult, result);
    }

    /**
     * Test of isEnabled method, of class CustomAnalyzer.
     */
    @Test
    public void testIsEnabled() {
        CustomAnalyzer instance = new CustomAnalyzer();
        boolean expResult = true;
        boolean result = instance.isEnabled();
        assertEquals(expResult, result);
    }
}
