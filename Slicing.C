// This code is for dividing the V0mult histogram in several slices in order to get the multiplicities like in which are oa histogram there is high mult and in
// in which area it is low. 

const int n = 1000;

int ntrack = 0, PID[n] = {0}, charge[n] = {0}, V0MMult = 0, a, integral;
double px[n] = {0}, py[n] = {0}, pz[n] = {0}, pT = 0, mass[n] = {0};
double eta[n] = {0}, rap[n] = {0}, phi[n] = {0}, energy[n] = {0};

void Slicing()
{
    gStyle->SetPalette(kRainBow);
    TFile *f = TFile::Open("/home/puri/pythia8308/examples/practice/finalpp/finalpp.root");

    TCanvas *c = new TCanvas("c", "c", 750, 600);
    TH1D *h8 = new TH1D("V0sp", "This is the V0sp distribution", 201, -0.5, 200.5);
    h8->SetLineColor(kRed);
    h8->SetMarkerColor(kRed);
    h8->SetMarkerSize(1);
    h8->SetMarkerStyle(20);
    h8->SetTitle("V0M Distribution; V0M/#Delta#eta; P(V0M)");
    h8->GetYaxis()->SetTitle("count");
    h8->GetXaxis()->SetTitle("V0m/4.3");
    c->SetLogy();
    c->Draw();

    TTree *theTree = (TTree *)f->Get("t");

    theTree->SetBranchAddress("ntrack", &ntrack); // ntrack is the size of the tree (fill only final chargedparticles)
    theTree->SetBranchAddress("V0MMult", &V0MMult);
    theTree->SetBranchAddress("PID", PID);
    theTree->SetBranchAddress("charge", charge);
    theTree->SetBranchAddress("px", px);
    theTree->SetBranchAddress("py", py);
    theTree->SetBranchAddress("pz", pz);
    theTree->SetBranchAddress("energy", energy);

    int nevents = 100000;
    for (int i = 0; i < nevents; i++)
    {
        theTree->GetEntry(i);
        h8->Fill(V0MMult);
    }
    h8->Draw();
    a = h8->Integral(); // total number of entries in the histogram for V0M
    // cout << a << endl;
    for (int k = 10; k < 100; k = k+10)
    {
        for (int j=1; j<=h8->GetNbinsX(); j++)

        {
            integral = h8->Integral(1,j);
            //  cout<<integral<<endl;

            if (integral >= (k) * a / 100.0)
            {
                 //cout<<(100.0 - k) * a / 100.0<<endl;
                 //cout<<j<<endl;
                 cout << h8->GetBinCenter(j) << endl;
                break;
            }
        }
    }
}