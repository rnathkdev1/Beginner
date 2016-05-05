using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;



public class STLparser : MonoBehaviour
{
	void Start()
	{
		
        string path = "liver.stl";
        string[] separators= {" ","\t",};
        
		List <Vector3> normals = new List<Vector3>();
		List <Vector3> vertices = new List<Vector3>();
		List <int> faces = new List<int>();
        
		int faceCount = 0;

        if (!File.Exists(path))
        {
            print("File doesnot exist\n");
            return;
        }

        string[] lines = File.ReadAllLines(path);
        foreach (string line in lines){
            string[] tokens = line.Split(separators, StringSplitOptions.RemoveEmptyEntries);
            if (tokens[0]=="facet" && tokens[1]=="normal"){
				

				normals.Add(new Vector3(float.Parse(tokens[2],System.Globalization.NumberStyles.Float),float.Parse(tokens[3],System.Globalization.NumberStyles.Float),float.Parse(tokens[4],System.Globalization.NumberStyles.Float)));

			}

            if (tokens[0]=="vertex"){
				vertices.Add(new Vector3(float.Parse(tokens[1],System.Globalization.NumberStyles.Float),float.Parse(tokens[2],System.Globalization.NumberStyles.Float),float.Parse(tokens[3],System.Globalization.NumberStyles.Float)));
				faces.Add (faceCount);
				faceCount+=1;
            }

        }

		Mesh mesh = new Mesh();
		mesh.vertices = vertices.ToArray ();
		mesh.triangles = faces.ToArray ();
		mesh.Optimize ();
		mesh.RecalculateNormals();

		MeshFilter mf = GetComponent<MeshFilter> ();
		mf.mesh = mesh;

		Debug.Log("Loaded Mesh");

		foreach (int face in faces) {
			print (face);
		}

		/*
		foreach (Vector3 vertex in vertices)
		{
			print(vertex[0] + " " + vertex[1]+ " "+ vertex[2]);

		}
		print (vertices.Count);
		*/
		
        //----------------------------------------------------CHECKER CODE-------------------------------------------------------//
       
		/*


        foreach (Vector3 vertex in vertices)
        {
            print(vertex);
        }
        
        foreach (Vector3 normal in normals){
            print(normal[0] + " " + normal[1]+ " "+ normal[2]);
        }

		
        */
        
        
	}
}	